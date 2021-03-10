// /d/guilds/alliance/leaders.c

#include <std.h>

inherit "/std/guilds/members.c";

void create()
{
    object ob;
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_indoors(1);
    set_light(2);
    //set_property("no teleport",1);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_short("Leaders' Room");
    set_long("%^CYAN%^Leader's Room%^RESET%^\n" +
             "%^BOLD%^%^WHITE%^You appear in a large room, a old, round " +
             "table stands in the center surrounded by three chairs. The " +
             "table is covered by a faded %^RESET%^%^BLUE%^blue %^BOLD%^" +
             "%^WHITE%^tablecloth. The chairs look expensive and are carved " +
             "from fine %^RESET%^%^ORANGE%^mahogany%^BOLD%^%^WHITE%^. Along " +
             "the solid granite stone wall hang numerous ragged banners and " +
             "fading paintings. One of the paintings catches your eye, maybe " +
             "you should take a closer look at it. In the far west corner of " +
             "the this room stands a desk, it looks a bit messy with paper " +
             "and bottles of ink everywhere. In the opposite corner is a " +
             "rather large shelf with many scrolls, documents and a few books " +
             "stored. You also notice a map on the wall above the desk, it's a " +
             "map of the surrounding regions. You get the feeling that great " +
             "decisions are made here.\n");
    set_listen("default", "You cannot really hear anything in here, it's very quiet.");
    set_smell("default", "You smell ink and burning torches.");
    set_exits(([
                   "east" : "/d/guilds/alliance/hall/main.c",
               ]));
    set_items(([
                   "painting" : "This is the painting of a large human Knight mounted on his steed. He is dressed in plate mail. On the left shoulder plate is the mark of %^BOLD%^Tyr%^RESET%^ and on the right one is what pictures a %^YELLOW%^Golden Dragon%^RESET%^. In his hand he wields a lance and carries a shield on the other. This man looks remarkable and appears to be an important person. You wonder who it is.",
               ]));
    set_guild_name("Alliance Reborn");
    set_guild_object("/d/guilds/alliance/obj/alliancering.c");
    //set_search("default",(:TO,"find_ring":));  This is now an active guild players have paid money into.  It's no different than a player house and non-members shouldn't be able to easily find the key. - Odin 5/4/2020
}

/*int found;
   int find_ring(){
     object ob;
    if (! found){
      tell_object(TP,"As you search you stumble upon a small ring, left for the ages on doubt.");
      tell_room(TO,"As "+TPQCN+" searches the room "+TP->query_subjective()+" finds a small ring, left for the ages no doubt.",TP);
      ob = new("/d/guilds/alliance/obj/alliancering.c");
      ob->move(TO);
     found = 1;
      return 1;
   }
   return 0;
   }*/
