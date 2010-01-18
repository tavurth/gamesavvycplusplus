//		Copyright (c) William Whitty 2010
//
//     This file is part of GSC. 
//
//     GSC is free software: you can redistribute it and/or modify
//     it under the terms of the GNU Lesser General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     GSC is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU Lesser General Public License for more details.
//
//     You should have received a copy of the GNU Lesser General Public License
//     along with GSC.  If not, see <http://www.gnu.org/licenses/>.

#ifndef GSC_QUADTREE
#define GSC_QUADTREE

#include "../../headers/GSC.h"
#include "../../misc/coords/point_2d/point_2d.h"

namespace gsc {
	template <class ContentType>
		class QuadtreePointer;

	//Node class for parent class {Quadtree}
	template <class ContentType>
		class Node {
			typedef typename std::vector<ContentType>::iterator QuadtreeLocation;
			int x, y, w, h;
			int depth;
			Node * nodeList[4];
			std::vector<ContentType> contents;

			//Returns true if {Point_2d} <p> is within the borders of <this>
			bool contains_point(Point_2d * p) const { return p->in_rect(x, y, w, h); }

			void populate_node_list() {
				//Populates the node list with new nodes
				int wDiv2 = w/2;
				int hDiv2 = h/2;

				nodeList[0] = new Node(x,         y,	     wDiv2, hDiv2, depth+1);
				nodeList[1] = new Node(x + wDiv2, y,	     wDiv2, hDiv2, depth+1);
				nodeList[2] = new Node(x + wDiv2, y + hDiv2, wDiv2, hDiv2, depth+1);
				nodeList[3] = new Node(x,	  y + hDiv2, wDiv2, hDiv2, depth+1);
			}

			void delete_content(QuadtreeLocation location) {
				contents.erase(location);
			}

			public:
				Node(int newX, int newY, int newW, int newH, int newDepth) {
					x = newX; y = newY; w = newW; h = newH; depth = newDepth;
					for (int i=0; i < 4; i++)
						nodeList[i] = NULL;
				}

				void set_x(int newX) { x = newX; }
				void set_y(int newY) { y = newY; }
				void set_w(int newW) { w = newW; }
				void set_h(int newH) { h = newH; }

				int  get_x() const   { return x; }
				int  get_y() const   { return y; }
				int  get_w() const   { return w; }
				int  get_h() const   { return h; }

				//Sort {Point_2d} <p> into the current {Node}
				QuadtreeLocation sort (Point_2d * p, int size, int maxDepth = 5) {
					//If the object is too big for the next level of the tree save it here
					if (depth >= maxDepth || size > w / 2 || size > h / 2) {
						contents.push_back(p);
						return contents.end();
					}

					//Intialise the nodeList if not already done
					if (nodeList[0] = NULL)
						populate_node_list();

					//Search until we find the correct child node
					for (int i=0; i < 4; i++)
						//If the point is inside <node> nodeList[i]
						if (nodeList[i]->contains_point(p))
							//Sort the point inside nodeList[i]
							nodeList[i]->sort_point(p, size);
				}
		};

	//This is the master class for dealing with quadtrees.
	template <class ContentType>
		class Quadtree : public Node<ContentType> {
			typedef typename std::vector<ContentType>::iterator QuadtreeLocation;
			std::vector<ContentType> contents;
			int maxDepth;

			public:
				Quadtree(int newX, int newY, int newW, int newH, int newMax = 5) : Node<ContentType>(newX, newY, newW, newH, 0) {
					maxDepth = newMax; 
				}

				std::vector<ContentType> get_contents() const { return contents; }

				//Sort {Point_2d} <p> into the current tree
				QuadtreePointer<ContentType> * sort(Point_2d * p, int size, QuadtreePointer<ContentType> * currentPos = NULL) {
					//If we have already sorted this point before
					if (currentPos){
						Node<ContentType> * node = currentPos->get_node();
						//If the point is still in the same node, do nothing
						if (node->contains_point(p))
							return;

						//Else: delete the content from the node and re-sort
						node->delete_content(currentPos->get_location());
						currentPos->set_location(Node<ContentType>::sort(p, size, maxDepth));
					}
					else {
						QuadtreeLocation newLocation = contents.push_back(Node<ContentType>::sort(p, size, maxDepth));
						return new QuadtreePointer<ContentType>(this, newLocation);
					}
				}
		};

	//A pointer that holds the current {Quadtree} <tree> and the <location> in {Node} <node> in said quadtree
	template <class ContentType>
		class QuadtreePointer {
			typedef typename std::vector<ContentType>::iterator QuadtreeLocation;

			Quadtree<ContentType> * tree;
			Node<ContentType>     * node;
			QuadtreeLocation      * location;

			public:
				QuadtreePointer (Quadtree<ContentType> * newCurrent, QuadtreeLocation * newLocation) {
					tree = newCurrent;
					location = newLocation;
				}

				void set_location(QuadtreeLocation newLocation) { location = newLocation; }
				void set(Quadtree<ContentType> * newTree) { tree = newTree; }
				void set_node(Node<ContentType> * newNode) { node = newNode; }

				QuadtreeLocation get_tree_location() const { return location; }
				Quadtree<ContentType> * get() const { return tree; }
				Node<ContentType> * get_node() const { return node; }
		};
}

#endif
