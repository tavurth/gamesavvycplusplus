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
		class Node : public Rect_2d {
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

				Node<ContentType> * sort(Point_2d * p, double size, int maxDepth = 5) {
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
				}
		};
}

#endif
