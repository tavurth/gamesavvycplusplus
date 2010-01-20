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

#include "../headers/GSC.h"
#include "../misc/coords/point_2d/point_2d.h"
#include "../misc/coords/rect_2d/rect_2d.h"

namespace gsc {
	template <class ContentType>
		class Node : public Rect_2d {
			private:
				typedef typename std::vector<ContentType>::iterator QuadtreeLocation;
				int depth;
				Node * nodeList[4];
				std::vector<ContentType> contents;

			public:
				Node(double newX, double newY, double newW, double newH, int newDepth) : Rect_2d(newX, newY, newW, newH) {
					for (int i=0; i < 4; i++)
						nodeList[i] = NULL;
					depth = newDepth;
				}

				int get_depth() const { return depth; }
				std::vector<ContentType> * get_contents() { return &contents; }
				void add(ContentType t) { contents.push_back(t); }

				//Returns true if {Point_2d} <p> is within the borders of <this>
				bool contains_point(Point_2d * p) { return p->in_rect(this); }

				void populate_node_list() {
					//Populates the node list with new nodes
					double x = p1->get_x();
					double y = p1->get_y();
					double wDiv2 = width/2;
					double hDiv2 = height/2;

					nodeList[0] = new Node(x,         y,	     wDiv2, hDiv2, depth+1);
					nodeList[1] = new Node(x + wDiv2, y,	     wDiv2, hDiv2, depth+1);
					nodeList[2] = new Node(x + wDiv2, y + hDiv2, wDiv2, hDiv2, depth+1);
					nodeList[3] = new Node(x,	  y + hDiv2, wDiv2, hDiv2, depth+1);
				}

				Node<ContentType> * sort(Point_2d * p, double size = 1, int maxDepth = 5) {
					//If the object is too big for the next level of the tree save it here
					if (depth >= maxDepth || size > width / 2.0 || size > height / 2.0)
						return this;
					
					//Intialise the nodeList if not already done
					if (nodeList[0] == NULL)
						populate_node_list();
					
					//Search until we find the correct child node
					for (int i=0; i < 4; i++)
						if (nodeList[i]->contains_point(p))
							return nodeList[i]->sort(p, size);

					return NULL;
				}
		};

	template <class ContentType>
		class QuadtreePointer;

	//Quadtree class, you should extend this to allow for sorting your own object types.
	template <class ContentType>
		class Quadtree : public Node<ContentType> {
			protected:
				std::vector<ContentType> * contents;
				int maxDepth;

			public:
				Quadtree(int newX, int newY, int newW, int newH, int newMax = 5) 
					: Node<ContentType>(newX, newY, newW, newH, 0) { maxDepth = newMax; }
				std::vector<ContentType> * get_contents() { return &contents; }

				void set_max_depth (int newMax) { maxDepth = newMax; }
				int  get_max_depth() const      { return maxDepth; }

				QuadtreePointer<ContentType> * sort(Point_2d * p, double size = 1, 
						QuadtreePointer<ContentType> * currentPosition = NULL) {

					if (currentPosition)
						return currentPosition->update_point(p, size);

					return new QuadtreePointer<ContentType>(this, Node<ContentType>::sort(p, size, maxDepth));
				}
		};

	//A pointer that holds the current {Quadtree} <tree> and the <location> in {Node} <node> in said quadtree
	template <class ContentType>
		class QuadtreePointer {
			typedef typename std::vector<ContentType>::iterator ContentIterator;

			Quadtree<ContentType> * tree;
			Node<ContentType>     * node;
			ContentType 	      content;

			public:
				QuadtreePointer (Quadtree<ContentType> * newTree, Node<ContentType> * newNode) {
					tree = newTree;
					node = newNode;
				}

				void remove_content () {
					ContentIterator it;
					std::vector<ContentType> * contents = node->get_contents();

					for (it = contents->begin(); it < contents->end(); it++)
						if (content == *it) {
							contents->erase(it);
							return;
						}
				}

				~QuadtreePointer () { remove_content(); }

				QuadtreePointer<ContentType> * update_point(Point_2d * p, int size) {
					if (node->contains_point(p))
						return this;

					remove_content();
					node = tree->Node<ContentType>::sort(p, size, tree->get_max_depth());

					return this;
				}

				void set(Quadtree<ContentType> * newTree) { tree = newTree; }
				void set_node(Node<ContentType> * newNode) { node = newNode; }
				void add_content(ContentType newContent) { 
					content = newContent;
			       		node->get_contents()->push_back(content);
				}

				Quadtree<ContentType> * get() const { return tree; }
				Node<ContentType> * get_node() const { return node; }
				ContentType get_content() const { return content; }
		};
}

#endif