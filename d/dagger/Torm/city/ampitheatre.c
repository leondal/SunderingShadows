//Added Madelyn, Disguise Teacher - Cythera 4/05
#include <std.h>
inherit CROOM;

void create()
{
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("%^BOLD%^The C%^ORANGE%^o%^WHITE%^r%^ORANGE%^a%^WHITE%^l %^CYAN%^Sky%^WHITE%^ Amphitheatre%^RESET%^");
   set_property("indoors",0);
   set_property("light",3);
   set_long(
   "%^RESET%^%^CYAN%^The amphitheatre is truly an ingenious design. There are"+
   " %^ORANGE%^oak benches %^CYAN%^arranged for a very large audience in a"+
   " semi-circle with the stage at the far east end. A%^BOLD%^%^WHITE%^"+
   " half-dome %^RESET%^%^CYAN%^covers the audience's seats, keeping them shaded"+
   " and protected from the elements while the other half with the stage is left"+
   " mostly open with several %^ORANGE%^arcing beams %^CYAN%^that reach across"+
   " and can be covered with tents if the weather gets too bad. A %^RED%^large"+
   " red rug %^CYAN%^trimmed in %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld"+
   " %^RESET%^%^CYAN%^stretches down the center aisle to steps that lead up to"+
   " the stage. The %^MAGENTA%^stage %^CYAN%^is slightly slanted towards the"+
   " audience, and the acoustics are wonderful here, making it easy to hear the"+
   " performers even over the crashing of the %^BOLD%^%^CYAN%^w%^BLUE%^a%^CYAN%^"+
   "v%^BLUE%^e%^CYAN%^s%^RESET%^%^CYAN%^. Towards the back, the stage actually"+
   " lifts higher to the right and left and is connected to the main portion by"+
   " a few steps. There are also several beams on the edges that are used to"+
   " support the ceiling beams as they reach across. Several%^BOLD%^%^WHITE%^"+
   " lanterns %^RESET%^%^CYAN%^are attached to them to help light the stage at"+
   " night. To the right and left of the stage are two walled sections, probably"+
   " %^BOLD%^%^BLUE%^dressing rooms%^RESET%^%^CYAN%^, from which the actors can"+
   " make their entrances. The backdrop for the stage is simply the%^BOLD%^"+
   " o%^RESET%^%^CYAN%^c%^BOLD%^e%^RESET%^%^CYAN%^a%^BOLD%^n%^RESET%^%^CYAN%^,"+
   " and many plays are performed near %^MAGENTA%^s%^ORANGE%^u%^YELLOW%^n"+
   "%^BOLD%^%^RED%^s%^MAGENTA%^e%^RESET%^%^MAGENTA%^t %^CYAN%^since that is such"+
   " a pretty setting.%^RESET%^"
   );
   set("night long",
   "%^RESET%^%^CYAN%^The amphitheatre is truly an ingenious design. There are"+
   " %^ORANGE%^oak benches %^CYAN%^arranged for a very large audience in a"+
   " semi-circle with the stage at the far east end. A%^BOLD%^%^WHITE%^"+
   " half-dome %^RESET%^%^CYAN%^covers the audience's seats, keeping them shaded"+
   " and protected from the elements while the other half with the stage is left"+
   " mostly open with several %^ORANGE%^arcing beams %^CYAN%^that reach across"+
   " and can be covered with tents if the weather gets too bad. A %^RED%^large"+
   " red rug %^CYAN%^trimmed in %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld"+
   " %^RESET%^%^CYAN%^stretches down the center aisle to steps that lead up to"+
   " the stage. The %^MAGENTA%^stage %^CYAN%^is slightly slanted towards the"+
   " audience, and the acoustics are wonderful here, making it easy to hear the"+
   " performers even over the crashing of the %^BOLD%^%^CYAN%^w%^BLUE%^a%^CYAN%^"+
   "v%^BLUE%^e%^CYAN%^s%^RESET%^%^CYAN%^. Towards the back, the stage actually"+
   " lifts higher to the right and left and is connected to the main portion by"+
   " a few steps. There are also several beams on the edges that are used to"+
   " support the ceiling beams as they reach across. Several%^BOLD%^%^WHITE%^"+
   " lanterns %^RESET%^%^CYAN%^are attached to them to help light the stage at"+
   " night. To the right and left of the stage are two walled sections, probably"+
   " %^BOLD%^%^BLUE%^dressing rooms%^RESET%^%^CYAN%^, from which the actors can"+
   " make their entrances. The backdrop for the stage is simply the%^BOLD%^"+
   " o%^RESET%^%^CYAN%^c%^BOLD%^e%^RESET%^%^CYAN%^a%^BOLD%^n%^RESET%^%^CYAN%^"+
   " with the %^WHITE%^s%^RESET%^%^WHITE%^t%^BOLD%^a%^RESET%^%^WHITE%^r%^BOLD%^"+
   "r%^RESET%^%^WHITE%^y %^BLUE%^n%^MAGENTA%^i%^BLUE%^g%^MAGENTA%^h%^BLUE%^t"+
   " %^CYAN%^sky above.%^RESET%^"
   );
   set_smell("default","The fresh ocean air drifts on the breeze.");
   set_listen("default","The waves pound rhythmically against the sea walls.");
   set_items(([
   ({"benches","oak benches"}) : "There are many oak benches for the audience,"+
   " they have been constructed so the back seats are raised higher than the"+
   " front, allowing everyone to have a good view of the stage.",
   ({"rug","red rug"}) : "%^BOLD%^%^RED%^There is a rich red rug trimmed in"+
   " %^YELLOW%^gold%^RED%^ that runs down the center aisle to some steps at"+
   " the front of the stage.%^RESET%^",
   ({"dome","half-dome"}) : "The structure of the ceiling is quite remarkable"+
   " and inventive. A solid half-dome of wood covers the audience's seats"+
   " while several arched beams connect over the stage. On close inspection"+
   " you can see hooks set up to attach large flaps of treated canvas in"+
   " case the weather gets too bad, allowing the entire amphitheatre to be"+
   " covered!",
   "stage" : "The stage is on the far east, it slants slightly downwards to"+
   " help with the acoustics as well as provide the higher tiers with a better"+
   " view. The back left and right sections of the stage are partially raised"+
   " with steps connecting to the main stage, allowing for a bit more diversity"+
   " in the settings.",
   "lanterns" : "Lanterns are attached to the wooden beams on the edges of"+
   " the stages, as well as smaller candles that have been set up in front of"+
   " the stage and sometimes along the aisles to help people see the actors"+
   " better at night.",
   ({"green room","dressing room","walled sections"}) : "There are two walled"+
   " rooms on the left and right side of the stage that serve as the dressing"+
   " rooms for the actors and are where they enter from during performances."+
   " The walls also help to lessen the pounding of the waves to simply a nice"+
   " background noise.",
   ]));
   set_exits(([
      "west" : "/d/dagger/Torm/city/c39",
      "stageleft" : "/d/dagger/Torm/city/bard1",
      "stageright" : "/d/dagger/Torm/city/bard2",
      "north" : "/d/dagger/Torm/city/arch1"
   ]));
   set_invis_exits(({"stageleft","stageright"}));
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
	
}

int GoThroughDoor(){
	if(avatarp(TP)) return 1;
	write("You realize that would be really dumb as you start to cross the line.");
	return 0;
}
void reset()
{
    object ob;
	::reset();
	if(!present("madelyn")) {
                find_object_or_load("/d/npc/madelyn")->move(TO);
	}
}