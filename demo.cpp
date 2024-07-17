
#include <iostream>
#include "Graph.h"
#include "pqueue.h"


int main(){
  graph g;

  /*
  g._add_edge("a b 2");
  g._add_edge("a c 2");
  g._add_edge("a d ");
  g._add_edge("b d ten");
  g._add_edge("a");
  */
  /*
  g.add_edge("a", "b");
  g.add_edge("b", "a");

  g.add_edge("b", "c");
  g.add_edge("d", "a");
  g.add_edge("b", "d");
  g.add_edge("a", "b");
  */


  // g.display();



  pqueue q(10, true);

  double priorities [] = { 10, 9,  8, 11, 12, 13,  14, 6, 7, 8 };
  //                       0   1   2   3   4   5    6  7  8  9
  int n=10;

  for(int i=0; i<n; i++) {
      q.insert(i, priorities[i]);
  }

  int id;
  double p;



  q.change_priority(5, 4);
  q.change_priority(8, 20);
  q.change_priority(3, 5);

  q.remove_by_id(2);

  for(id=0; id<q.capacity(); id++) {
      if( q.get_priority(id, p))
          printf("(get_priority): id: %d ; p: %lf\n", id, p);
      else
          printf("(get_priority): no entry for id: %d\n", id);
  }

  printf("\n");

  while(q.size()) {
      q.delete_top(id, p);
      printf("(delete_top): id: %d ; p: %lf\n", id, p);
  }

  printf("\n");
  printf("size: %d\n", q.size());


  return 0;
}

