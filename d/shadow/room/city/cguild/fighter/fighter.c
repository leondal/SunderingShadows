#include <std.h>
inherit ROOM;

void create() {
::create();
set_light(2);
set_indoors(1);
set_short("Fighters guild");
set_long("%^BOLD%^%^WHITE%^"
   "This is the fighter's hall.  Many warriors from the city and "+
   "surrounding areas gather here for different reasons.  Some for "+
   "information, others to seek out training under the renowned "+
   "warriors of the hall, and others to challenge their skill in a "+
   "battle against some of the world's best.  "+
   "This circular room serves as the main lobby.  It has a dome-like "+
   "ceiling and walls built from stone blocks shipped in from the "+
   "dwarves of the north.  On the walls are very large paintings of "+
   "some of history's greatest warriors.\n"+
   "There are four arched doorways here.  One leads out into the "+
   "city, another to a recreational area, another to the guild store, "+
   "and one other to the field of battle.\n"
);

set_items(([
   "walls" : "The walls are carved finely by the dwarves of the north.",
   "ceiling" : "The ceiling is built in a magnificent dome that reaches high overhead.",
   "paintings" : "The paintings are detailed drawings of history's greatest warriors. Maybe you would like to look at one specifically?",
   "painting 1" : "This is a painting of a %^BOLD%^%^RED%^red-headed%^RESET%^ female firbolg. She is standing proud wielding a great sword in one hand and holding a shield in the other. In the bottom right hand corner the name %^BOLD%^%^YELLOW%^'Lahnna Fergus'%^RESET%^ is etched in the painting.",
   "painting 2" : "This is a painting of a half-elf holding on to a %^RESET%^%^BLUE%^dark scythe%^RESET%^. Covered in dark armor, he has a sarcastic smirk on his face. In the bottom right hand corner the name %^BOLD%^%^RED%^'Beowulf'%^RESET%^ is etched in the painting.",
   "painting 3" : "This is a painting of a bald middle aged man. His eyes are narrowed as he grips his %^BOLD%^%^WHITE%^axe%^RESET%^ tightly. In the bottom right hand corner the name %^RESET%^%^ORANGE%^'Girruuth'%^RESET%^ is etched in the painting.",
   "painting 4" : "This is a painting of a %^BOLD%^%^RED%^scarlet haired%^RESET%^ male human. He is protected by light armor, wielding a scimitar, and wears a large brimmed decorated hat. In the bottom right hand corner the name %^BOLD%^%^RED%^'Saradin Torvall'%^RESET%^ is etched in the painting.",
   "painting 5" : "This is a painting of a silver eyed male human. Wearing heavy armor, this man stands with a straight back and keeps a hand on the hilt of his %^BOLD%^%^WHITE%^longsword%^RESET%^. In the bottom right hand corner the name %^BOLD%^%^RED%^'Adlon Nortvholk'%^RESET%^ is etched in the painting.",
   "painting 6" : "This is a painting of a gray eyed, brown haired male human. He is standing at attention in his shining armor, which bears the symbol of %^BOLD%^%^WHITE%^Torm%^RESET%^. In the bottom right hand corner the name %^BOLD%^%^BLACK%^'Duncan of Clan Stormhammer'%^RESET%^ is etched in the painting.",
   "painting 7" : "This is a painting of a titanic iron clad firbolg. High above his head he holds a gigantic %^BOLD%^%^BLUE%^battle hammer%^RESET%^. In the bottom right hand corner the name %^BOLD%^%^YELLOW%^'Coyotte'%^RESET%^ is etched into the painting.",
   "painting 8" : "This is a painting of a massive blonde haired firbolg. He stands tall in large full plate that is decorated with the holy symbol of %^BOLD%^%^RED%^Tempus%^RESET%^. In the bottom right hand corner the name %^BOLD%^%^BLUE%^'Tanamen'%^RESET%^ is etched into the painting.",
   "painting 9" : "This is a painting of a large female firbolg. She stands amongst rolling hills, looking into the distance, with a %^BOLD%^%^WHITE%^scythe%^RESET%^ resting on her back. In the bottom right hand corner the name %^BOLD%^%^GREEN%^'Spyder'%^RESET%^ is etched into the painting.",
   "painting 10" : "There is nothing where the next painting would be, maybe your painting could be here someday?",
   ]));
   set_listen("default","%^RESET%^%^ORANGE%^You hear the chatter of many people discussing combat, past fights, and challenges.");
   set_smell("default","%^RESET%^%^GREEN%^This place smells like stone.");
set_exits( ([ "out" : "/d/shadow/room/city/cguild/fighter/ac_fighter",
"north" : "/d/shadow/room/city/cguild/fighter/dart_room",
"field" : "/d/shadow/room/city/cguild/fighter/battlefield",
"store" : "/d/shadow/room/city/cguild/fighter/f_store",
]) );

/*  ooc boards moved to remote access
ob = new("/std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board" }) );
   ob->set_board_id("fighter");
   ob->set_max_posts(30);
   ob->set_ooc_board(1);
    ob->set_location("/d/shadow/room/city/cguild/fighter/fighter.c");
ob->set("short", "The fighters update board");
  ob->set("long","%^BOLD%^ORANGE%^This is where all the fighters keep up to date on things "
"that are going on that concern fighters.\n%^RESET%^BLUE%^");
*/
}

/*
void init(){
    ::init();
    add_action("fighterstuff", "remove");
    add_action("fighterstuff", "answer");
    add_action("fighterstuff", "post");
    add_action("fighterstuff", "edit");
}

int fighterstuff(){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return 0;
    tell_object(TP, "That is not for you.");
    return 1;
}
*/
