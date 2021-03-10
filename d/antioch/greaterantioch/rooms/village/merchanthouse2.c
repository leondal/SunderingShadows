#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit CROOM;
object ob;

void create()
{
    ::create();
    set_property("no teleport",1);
    set_name("merchanthouse2");
    set_property("indoors",1);
    set_property("light",3);
    set_short("%^RESET%^%^CYAN%^Upstairs in a Large House%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^As you arrive on the second floor you realize the floorplan of this house is very simple."+
             " The floor here is covered with a %^RESET%^%^RED%^carpet %^BOLD%^%^WHITE%^and has candles affixed to the wall"+
             " by small iron %^BOLD%^%^CYAN%^sconces%^BOLD%^%^WHITE%^. There is only one way to proceed from here, and that is"+
             " into the bedroom ahead.");

    set_smell("default","\n%^BOLD%^%^YELLOW%^The smell of leathers and rustic wood is here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear the faint crackle of a fire.%^RESET%^");

    set_exits(([
        "bedroom"  : HAMLET"merchanthouse3",
		"stairs"	: HAMLET"merchanthouse1",
	]));
    set_items(([
      "sconces" : "%^BOLD%^%^WHITE%^The sconces have multiple %^BOLD%^%^YELLOW%^candles %^BOLD%^%^WHITE%^on them, lighting the area with a dull glow.",
      "carpet" : "%^RESET%^%^RED%^The carpet is plush to walk on and is very thick.",
   ]) );
   set_pre_exit_functions(({"bedroom"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
     if(query_verb() == "stairs") {
            return 1;}

    if(query_verb() == "bedroom") {
    if(member_array("You Left the Wife to Her Fate",TP->query_mini_quests())!=-1){
        write("You might as well, let him be.");
        return 0;}
        else {
        return 1;}
}}

