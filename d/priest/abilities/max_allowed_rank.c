// Pator@ShadowGate
// July 16 1996
// Give the highest unallowed druidrank

#include <druids.h>

int max_unallowed_rank();

int max_unallowed_rank() {
  int rank, inc, number;
  number = sizeof(RANKING);
  rank = 0;
  inc = 0;
  for (inc ;inc < number; inc++)
    { if (member_array(RANK_STRING[inc], RESTRICTED_NAMES) == -1)
         rank++;
    }
  rank--;
  return rank;
}
