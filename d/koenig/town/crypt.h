#include <std.h>
 
#define ROOMS "/d/koenig/town/"
#define OBJS "/d/koenig/town/itmes/"
#define MONS "/d/koenig/town/mon/"
#define TP this_player()
#define ENV environment(TP)
#define TPC (string)this_player()->query_cap_name()
#define TPP this_player()->query_possessive()
#define TPO this_player()->query_objective()
#define TPS this_player()->query_subjective()
