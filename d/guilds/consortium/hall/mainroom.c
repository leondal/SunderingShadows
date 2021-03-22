#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_light(2);
    set_property("indoors", 1);
   set_property("no teleport", 1);
    set_short("Main Hall");
    set_long(
      "You have entered the breath-taking tower of the Thaumaturgical Consortium.  Here is where those deemed the best minds in the realms study and research to better their personal knowledge.  Tapestries and Paintings line the walls depicting the growth of the lands as time has passed.  An oversized hourglass sits in one corner of the room and in the opposite corner a globe.  Double doors to the east lead to the Hall of the Council where the Leaders meet to discuss events and changes."
    );
    set_listen("default", "You hear the murmer of chanting mages.");
    set_smell("default", "Burning incense is strong in the air.");
    set_items( ([
      "tapestries" : "These beautiful tapestries taken together give you a beautiful depiction of the history of the realms.",
      "hourglass" : "This hourglass silently counts away time.",
    ]) );
    set_exits( ([
    ]) );
}
