#include <std.h>
#include "../lgnoll.h"

inherit STORAGE"ccenter.c";
int breakx,brokenx;
void create(){
   ::create();
   set_long((:TO,"long_desc":));
   breakx=0;
   brokenx=0;
   add_item("barricade","%^ORANGE%^ This is huge! Standing nearly 12 feet tall and only the Gods knows how thick. It is build to last .. or keep something very big at bay.");
   set_search("barricade","%^ORANGE%^There are no ways around this massive barricade. But you could smash through it. It will take some work and strength!");
   set_exits(([
      "east":ROOMS"27",
      //"north" : ROOMS"26",
	  "south" : ROOMS"21"
   ]));

}

string long_desc(){
	if(brokenx){
return("%^GREEN%^You are standing in what must be the %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lls' "+
	"%^GREEN%^main-camp%^YELLOW%^. %^RESET%^%^GREEN%^A multitude of huts and crude leather tents litter the whole "+
	"area. The smell and sounds of %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lls "+
	"%^BOLD%^%^BLACK%^'%^RESET%^%^ORANGE%^communicating%^BOLD%^%^BLACK%^' %^RESET%^%^GREEN%^can be heard from "+
	"other places in the camp. Luckily the %^BOLD%^%^BLACK%^h%^RESET%^u%^BOLD%^%^BLACK%^ts %^RESET%^%^GREEN%^and "+
	"%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nts %^RESET%^%^GREEN%^provide ample cover to move around unnoticed. "+
	"Often a %^BOLD%^%^BLACK%^fight %^RESET%^%^GREEN%^between two %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lls "+
	"%^GREEN%^or some %^CYAN%^poor victim %^GREEN%^of their appetite can be heard%^ORANGE%^, %^GREEN%^muffling out the "+
	"sound yo%^RED%^u %^GREEN%^might make%^YELLOW%^. %^RESET%^%^GREEN%^Walking around the camp one will have to watch "+
	"their steps%^YELLOW%^. %^RESET%^%^MAGENTA%^H%^RED%^a%^MAGENTA%^lf-e%^RED%^a%^MAGENTA%^ten %^CYAN%^victims %^GREEN%^of "+
	"various races lay spread all over the ground in various degrees of %^MAGENTA%^decomposition%^YELLOW%^."+
	"%^BOLD%^%^BLACK%^ A large barricade dominates the western part of the area. Even though it is massive someone or something has broken through it.\n");
	}
	return("%^GREEN%^You are standing in what must be the %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lls' "+
	"%^GREEN%^main-camp%^YELLOW%^. %^RESET%^%^GREEN%^A multitude of huts and crude leather tents litter the whole "+
	"area. The smell and sounds of %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lls "+
	"%^BOLD%^%^BLACK%^'%^RESET%^%^ORANGE%^communicating%^BOLD%^%^BLACK%^' %^RESET%^%^GREEN%^can be heard from "+
	"other places in the camp. Luckily the %^BOLD%^%^BLACK%^h%^RESET%^u%^BOLD%^%^BLACK%^ts %^RESET%^%^GREEN%^and "+
	"%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nts %^RESET%^%^GREEN%^provide ample cover to move around unnoticed. "+
	"Often a %^BOLD%^%^BLACK%^fight %^RESET%^%^GREEN%^between two %^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^lls "+
	"%^GREEN%^or some %^CYAN%^poor victim %^GREEN%^of their appetite can be heard%^ORANGE%^, %^GREEN%^muffling out the "+
	"sound yo%^RED%^u %^GREEN%^might make%^YELLOW%^. %^RESET%^%^GREEN%^Walking around the camp one will have to watch "+
	"their steps%^YELLOW%^. %^RESET%^%^MAGENTA%^H%^RED%^a%^MAGENTA%^lf-e%^RED%^a%^MAGENTA%^ten %^CYAN%^victims %^GREEN%^of "+
	"various races lay spread all over the ground in various degrees of %^MAGENTA%^decomposition%^YELLOW%^."+
	"%^RESET%^%^ORANGE%^ A huge barricade dominates the western part of the area.%^RESET%^\n");
}

void reset(){
   ::reset();
   brokenx=0;
   breakx=0;
   set_exits(([
      "east":ROOMS"27",
      //"north" : ROOMS"26",
	  "south" : ROOMS"21"
   ]));
   switch(random(5)){
      case 0..2:  tell_room(TO,"%^BOLD%^%^BLACK%^You hear a %^ORANGE%^li%^RED%^o%^ORANGE%^n's "+
	  "%^RED%^roar %^BLACK%^followed by the death-cry of a %^RESET%^%^ORANGE%^gnoll.");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^A %^CYAN%^gust of wind blows %^ORANGE%^through the "+
	  "camp, lifting the %^BOLD%^%^BLACK%^stink %^RESET%^%^ORANGE%^of %^MAGENTA%^death %^ORANGE%^and "+
	  "%^MAGENTA%^decay %^ORANGE%^for a precious few seconds.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^%^BLACK%^A %^RED%^horrible death cry %^BLACK%^of another of the "+
	  "gnolls' victims can he heard from somewhere in the camp.");
               break;
         }
}


void init(){
	::init();
	add_action("smash","smash");
}

int smash(string str){
	if(!str){notify_fail("smash what?"); return 0;}
	if(str != "barricade"){notify_fail("Do you want to smash something?"); return 0;}
	if(brokenx){notify_fail("Someone already went through the barricade."); return 0;}
	if(TP->query_paralyzed()){notify_fail("You are already smashing at the barricade."); return 0;}
	if(TP->query_stats("strength")>random(30)){
		breakx++;
		tell_object(TP,"You manage to smash through some of the barricade!");
		tell_room(ETP,TP->QCN+" manages to smash through some of the barricade!");
		TP->set_paralyzed(random(5)+5,"%^RED%^You bash and smash at the barricade!");
		if(breakx>5){
			brokenx=1;
			tell_object(TP,"After a lot of hard work, you finally break through the barricade!");
			tell_room(ETP,TP->QCN+" finally managed to break through the barricade!",TP);
			set_exits(([
			"east":ROOMS"27",
			"west" : ROOMS"36",
			//"north" : ROOMS"26",
			"south" : ROOMS"21"
		]));}return 1;
	}
	tell_object(TP,"Try as you might, the barricade is too solid. You don't manage to break it even a little!");
	TP->set_paralyzed(random(5)+5,"%^RED%^You bash and smash at the barricade!");
	tell_room(ETP,TP->QCN+" grunts and groans ... But "+TP->QS+" don't have the strength to break through the barricade!",TP);
return 1;}