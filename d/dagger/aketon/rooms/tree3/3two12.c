#include "/d/dagger/aketon/short.h"

inherit VAULT;
int FLAG;
void create() {
   string str;
   int num;
   object obj, obj2, money;

   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_short("A mage's workroom");
   set_long("%^GREEN%^A mage's workroom%^RESET%^\n"+
   "This is obviously the workroom of a mage. This room is also shaped"+
   " into a hexagon and you notice many scorch marks on the walls,"+
   " ceiling, and floor. You notice swirling runes of enchantment"+
   " appearing and disappearing about the room. They are probably"+
   " runes of protection and this is where the mage can test new"+
   " spells or summon various monsters from different planes. The"+
   " room is bare except for a wooden chair in one corner. Something"+
   " here makes your skin crawl and you feel as though you're being"+
   " watched.");
   set_smell("default","There is a faint charred smell to the room.");
   set_listen("default","The silence here is absolute.");
   set_door("ebony door",RPATH3+"3two13","east",0);
   set_exits( (["east":RPATH3+"3two13"]) );
   if(!random(6)) new(MPATH+"mimic")->move(TO);
   else {
      obj = new("/d/shadow/obj/misc/chest");
      obj->move(TO);
   obj->set_id(({"chest"}));
      obj->set_key("chestkey");
      obj->set_short("A large chest");
      obj->set_long("You see a large chest.  It appears to be made of wood"+
      " and iron and is large enough to hold much treasure or other items."+
      "  The lock appears to be built into the front of the chest.");
      obj->set_open_long("This is a large chest made from wood and"+
      " iron.\nIt is open.");
      obj->set_closed_long("This is a large chest made from wood and"+
      " iron.\nIt is closed.");
      obj->set_id(({"chest","large chest"}));
   obj->set_weight(75);
      money = new("/std/obj/coins");
      money->set_money("gold",random(2000)+250);
      money->set_money("electrum",random(1000)+175);
      money->set_money("platinum",random(200)+10);
      money->set_money("silver",random(4000)+500);
      money->move(obj);
      switch(random(7)) {
         case 0:
            str = "diamond dust";
            num = random(3)+1;
            break;
         case 1:
            str = "emerald";
            num = random(8)+3;
            break;
         case 2:
            str = "pearl";
            num = random(15)+10;
            break;
         case 3:
            str = "dragon scale";
            num = random(5)+2;
            break;
         case 4:
            str = "drop of blood";
            num = random(50)+50;
            break;
         case 5:
            str = "pinch of special dust";
            num = random(30)+20;
            break;
         case 6:
            str = "powdered silver";
            num = random(50)+10;
            break;
      }
      obj2 = new("/d/magic/store_comp.c");
      obj2->set_name(str);
      obj2->set_id(({str,"component"}));
      obj2->set_short(capitalize(str)+" (a spell component)");
      obj2->set_long("     "+num+" "+str+""+
      ""+obj2->query_long());
      obj2->set_comp_quantity(num);
      obj2->move(obj);
      obj->toggle_closed();
      obj->set_lock("locked");
      obj->lock_difficulty(80);
    	set_trap_functions(
    		({"chest","chest","chest"}),
    		({"get_me","get_me2","get_me3"}),
    		({"get","pick","open"})
    	);   
   }
	FLAG=0;
}
int get_me(string str){
	object mon;
	if(FLAG == 1)return 0;
	if(str == "chest"){
		FLAG = 1;
		tell_room(ETP,"%^BOLD%^%^RED%^A portion of the wall starts to move and then "+
			"steps away.\nBaleful red eyes fix on you from a beast that appears "+
			"to made of stone and, until now, blended so well against the wall "+
			"that you did not detect it till it moved.");
		tell_room(ETP,"%^BOLD%^%^RED%^The malefic gargoyle leaps at "+TPQCN+"!",TP);
		tell_object(TP,"%^BOLD%^%^RED%^The gargoyle leaps at your throat!");
      	mon = new(MPATH+"gargoyle2");
      	mon->move(TO);
      	mon->force_me("kill "+TP->query_name());
		return 0;
	}
	return 0;
}
int get_me2(string str){
	object mon;
	if(FLAG == 1)return 0;
	if(str == "chest"){
		FLAG = 1;
		tell_room(ETP,"%^BOLD%^%^RED%^A portion of the wall starts to move and then "+
			"steps away.\nBaleful red eyes fix on you from a beast that appears "+
			"to made of stone and, until now, blended so well against the wall "+
			"that you did not detect it till it moved.");
		tell_room(ETP,"%^BOLD%^%^RED%^The malefic gargoyle leaps at "+TPQCN+"!",TP);
		tell_object(TP,"%^BOLD%^%^RED%^The gargoyle leaps at your throat!");
      	mon = new(MPATH+"gargoyle2");
      	mon->move(TO);
      	mon->force_me("kill "+TP->query_name());
		return 0;
	}
	return 0;		
}
int get_me3(string str){
	object mon;
	if(FLAG == 1)return 0;
	if(str == "chest"){
		FLAG = 1;
		tell_room(ETP,"%^BOLD%^%^RED%^A portion of the wall starts to move and then "+
			"steps away.\nBaleful red eyes fix on you from a beast that appears "+
			"to made of stone and, until now, blended so well against the wall "+
			"that you did not detect it till it moved.");
		tell_room(ETP,"%^BOLD%^%^RED%^The malefic gargoyle leaps at "+TPQCN+"!",TP);
		tell_object(TP,"%^BOLD%^%^RED%^The gargoyle leaps at your throat!");
      	mon = new(MPATH+"gargoyle2");
      	mon->move(TO);
      	mon->force_me("kill "+TP->query_name());
		return 0;
	}
	return 0;
		
}
