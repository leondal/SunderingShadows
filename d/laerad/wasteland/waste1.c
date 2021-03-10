// Updated by ~Circe~ 8/14/15 to lay the groundwork for Asgard Keep
// updated description to match other changes, last change 4/7/03 *Styx*  12/20/03

#include <std.h>
inherit ROOM;
// object ob;

void create(){
    ::create();
    set_name("Wasteland");
    set_short("%^ORANGE%^Wasteland%^RESET%^");
    set_terrain(DESERT);
    set_travel(FOOT_PATH);
    set_property("light",2);
    if(random(4))
	set_property("no sticks", 1);
/* Original description
    set_long("%^ORANGE%^You are at the edge of a barren plain.  The earth "
	"appears cracked "
	"and dead with no vegetation other than an occasional unusually large "
	"cactus.  A wicked wind bites at your face, blowing sand into your eyes."
	"  Here and there a %^YELLOW%^sulfurous mist %^RESET%^%^ORANGE%^spews "
	"from a new fissure in the ground.  To the west you can see "+
	"the docks of Laerad and the lifeless wasteland continues "
	"to the east."
	"\nThere is a %^GREEN%^sign %^RESET%^here."
    );
*/
    set_long("%^ORANGE%^You are at the edge of a barren plain.  The earth "
	"appears cracked "
	"and dead with no vegetation other than an occasional unusually large "
	"cactus.  A wicked wind bites at your face, blowing sand into your eyes."
	" Here and there a %^YELLOW%^sulfurous mist %^RESET%^%^ORANGE%^spews "
	"from a new fissure in the ground.  To the west you can see "+
	"the docks of Laerad and the lifeless wasteland continues "
	"to the east.\n\n%^BOLD%^%^BLACK%^The north is bordered by a "
      "%^RESET%^%^ORANGE%^wooden palisade wall %^BOLD%^%^BLACK%^with no obvious openings here.%^RESET%^"
	"\n\n%^ORANGE%^There is a %^GREEN%^sign %^RESET%^here.\n"
    );

    set_smell("default","A salty breeze blows past your face.");
    set_listen("default","You hear little over the howling of the wind in your ears.");
    set_items(([
       "sign" : "Perhaps you should read it.",
       ({"fence","wall","palisade"}) : "The wall is tall and made from quality "
          "wood that has clearly been imported. From the looks of it, the wall was raised recently."
    ]));
/*  removing ooc boards & others that have outlived their usefulness  *Styx*  4/6/03
    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({"board","comment board"}) );
    ob->set_board_id("ldboard");
    ob->set_max_posts(30);
    ob->set_location("/d/laerad/wasteland/waste1");
    ob->set_short("Laerad's comment board");
    ob->set_long("This is Laerad's comment board.  Please feel free to post your ideas and comments here for everyone to read.  ");
*/
    set_exits( ([
	"west":"/d/shadow/virtual/sea/laerad.dock",
	"east":"/d/laerad/wasteland/waste2"
    ]) );
    find_object_or_load("/d/laerad/parnelli/systyquah/sys001");
    //find_object_or_load("/d/laerad/cavern1/cav001");
    find_object_or_load("/d/laerad/swamp/swamp84");
}
void init(){
    ::init();
    add_action("read_sign","read");
}
int read_sign(string str){
    if(!str) return notify_fail("\nRead what?");
    if("sign" != str) return 0;
//    this_player()->more("/d/laerad/ISLAND");
    TP->more("/d/laerad/NewMap");
    return 1;
}
