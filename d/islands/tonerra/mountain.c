//jungle.c
//updated to make sure there is a down exit to ankheg rooms - should not be trapped - Saide

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit "/std/room.c";

string what, dir;
object room;
int flag;

string * features = ({
        "%^CYAN%^The slope is unusually steep here.%^RESET%^",
            "%^CYAN%^A couple of %^ORANGE%^bushes%^CYAN%^ grow here.%^RESET%^",
            "%^CYAN%^The %^BOLD%^wind%^RESET%^%^CYAN%^ is pushing you to the mountain.%^RESET%^",
            "%^ORANGE%^Some animals, perhaps goats, passed through here recently.%^RESET%^",
            "%^CYAN%^A %^GREEN%^lone tree%^CYAN%^ grows here.%^RESET%^",
            "%^CYAN%^A couple of %^ORANGE%^h%^BOLD%^%^BLACK%^awk%^RESET%^%^ORANGE%^s%^CYAN%^ cast shadows over you.%^RESET%^",
            "%^CYAN%^A flat %^BOLD%^%^BLACK%^boulder%^RESET%^%^CYAN%^ forms a natural seat here.%^RESET%^",
            "%^CYAN%^Some rocks slid through the path here, making it harder to pass.%^RESET%^",
            "%^CYAN%^%^GREEN%^Toxic fumes%^CYAN%^ rise here through the ground.%^RESET%^",
            "%^CYAN%^A %^WHITE%^geyser%^CYAN%^ forms a natural hot spring here.%^RESET%^",
            "%^CYAN%^An abandoned campfire still %^BOLD%^%^BLACK%^gl%^RED%^i%^BLACK%^mmers%^RESET%^%^CYAN%^ here.%^RESET%^",
            "%^CYAN%^Some people passed through here recently, their steps are seen in the gravel.%^RESET%^",
            "%^CYAN%^There is %^RED%^blood%^CYAN%^ on the road.%^RESET%^",
            "%^CYAN%^A weathered spear with a %^BOLD%^%^WHITE%^skull%^RESET%^%^CYAN%^ hanging on its shaft is stuck into ground here.%^RESET%^",
            "%^CYAN%^Human %^BOLD%^%^WHITE%^bones%^RESET%^%^CYAN%^ lie on the side.%^RESET%^",
            "%^CYAN%^An unusually big pile of %^ORANGE%^shit%^CYAN%^ almost blocks the road here. You see some %^BOLD%^%^WHITE%^bones%^RESET%^%^CYAN%^ in it.%^RESET%^",
    });

void create(){
	::create();
	set_terrain(SCRUB_LANDS);
	set_travel(FOOT_PATH);
    set_short("%^CYAN%^Side of the %^RED%^volcano%^RESET%^");
    set_long("%^CYAN%^Side of the %^RED%^volcano%^RESET%^
%^CYAN%^You are making your way up the side of a large volcano. The slope is steep, but there seems to be a well-worn path. You can see a large building about halfway up the side of the mountain."+make_fdesc());
}

void reset(){
	object *temp,ob;
	int i;
	string *str;
	::reset();

	if(!pointerp(TO->query_exits()) || !sizeof(TO->query_exits())){
		flag =1;

		return;
	}
    if(!objectp(room))
    {
        if(query_property("ankeg_room"))
        {
            remove_property("ankeg_room");
            remove_exit("down");
        }
    }

	if(!present("bad boy")){
		if(!random(10)){
            str = (string *)TO->query_exits();
            str -= ({"down"});
            dir = str[random(sizeof(str))];

			switch (random(50))
            {

			case 0..5:
				set_trap_functions(({dir}),({"ankheg"}),({dir}));
				add_item("ground","The ground to the "+dir+" seems weak.");
				what = "ankheg&"+dir;
				break;
			case 10..17:
				set_trap_functions(({dir}),({"native"}),({dir}));
				add_item("bushes","There seems to be something hidden in the scrub brush toward the "+dir+".");
				what = "native&"+dir;
				break;
			case 18..20:

				ob = new(MON+"cyclops");
				ob->add_id("bad boy");
				ob->move(TO);
				if(!random(3)){
				   ob = new(MON+"cyclops");
				   ob->add_id("bad boy");
				   ob->move(TO);
				}
				break;
			case 21..25:
   			      i= random(4)+1;
			      while(i--){

      				ob = new(MON+"galebduhr");
				ob->add_id("bad boy");
				ob->move(TO);
			      }
				break;
			case 26..43:
				temp = "/d/islands/tonerra/mon/tonerra_d"->make_party(TO);
				for(i=0;i<sizeof(temp);i++){
					temp[i]->add_id("bad boy");
				}
			}
		}
	}
}

int ankheg(){
	string verb;
	object ob;

	verb = query_verb();

	tell_room(TO,"As "+TPQCN+" wanders "+verb+" the ground below "+TP->query_objective()+" shudders and opens.",TP);
	tell_object(TP,"As you walk "+verb+" the ground shudders and opens under you.");
	if(!objectp(room)){

	 room = new(PATH+"ankheghouse");
	 //room->add_exit(TO->query_exit(verb),"up");
     room->add_exit(TO->query_exit(dir),"up");
	}
    TO->query_exit(dir)->add_exit(room, "down");
    TO->query_exit(dir)->set_property("ankeg_room", 1);
    TO->query_exit(dir)->set_ankheg_room(room);
	TP->move_player(room);
	//toggle_trap(verb);
	return 1;
}


int native(){
	string verb;
	object ob,*inven,tmp;
	int i,j,k,l;

	verb = query_verb();
	if(TP->query_invis()) return 0;
	tell_room(TO,"%^BOLD%^As "+TPQCN+" wanders "+verb+" the bushes around "+TP->query_objective()+" come alive and spears fly through the air.",TP);
	tell_object(TP,"%^BOLD%^As you walk "+verb+" the bushes around you come alive and spears fly through the air!");
	inven = all_living(TO);
	l = sizeof(inven);
	ob= new(MON+"native");
	ob->add_id("bad boy");
	ob->move(TO);
	for(k=0;k<l;k++){
		ob->kill_ob(inven[k],1);
	}
	ob= new(MON+"native");
	ob->add_id("bad boy");
	ob->move(TO);
	for(k=0;k<l;k++){
		ob->kill_ob(inven[k],1);
	}
	ob= new(MON+"nativeS");
	ob->add_id("bad boy");
	ob->move(TO);
	for(k=0;k<l;k++){
		ob->kill_ob(inven[k],1);
	}
	tmp = new("/d/common/obj/weapon/spear_lg");
      tmp->set_property("enchantment",3);
	if(ob->Thaco(1,TP,tmp) < (random(20)+4)){
		tell_object(TP,"You are hit with a spear!");
		tell_room(TO,TPQCN+" is hit with a spear.",TP);
		ob->do_hits(TP, tmp, "torso");
	}
	if(ob->Thaco(1,TP,tmp) < (random(20)+4)){
		tell_object(TP,"You are hit with a spear!");
		tell_room(TO,TPQCN+" is hit with a spear.",TP);
		ob->do_hits(TP, tmp, "torso");
	}
	j = random(5)+4;
	for(i=0;i<j;i++){
		k = random(sizeof(inven));
		if(ob->Thaco(1,inven[k],tmp) < (random(20)+4)){
			tell_object(inven[k],"You are hit with a spear!");
			tell_room(TO,inven[k]->query_cap_name()+" is hit with a spear.",inven[k]);
			ob->do_hits(inven[k], tmp, "torso");
		}
	}
     TP->add_attacker(ob);
     TP->continue_attack();
// adding check for objectp(TP) to try to stop bugging *Styx*  11/15/02
     if(objectp(TP))  TP->remove_attacker(ob);
        tmp->remove();	// added by Styx 11/03/02 to clean up objects w/no environment
	tell_room(TO,"%^BOLD%^%^BLUE%^Natives appear from the bushes and attack.");

	toggle_trap(verb);
	return 1;
}

void init(){
	if(flag){
		reset();
		flag =0;
	}
	::init();
}

string query_long(string str){
	string hold,one,two;

	hold = ::query_long(str);

	if(!what) return hold;

	sscanf(what,"%s&%s",one,two);
	if(!one || !trapped(two)) return hold;

	switch (one){
		case "native":
			hold += "The bushes seem to shake every now and then.";
			return hold;
			break;
		case "tasloi":
			hold += "The trees are strangely quiet";
			return hold;
			break;
		case "ankheg":
			hold += "The ground is looser then the rest of this path.";
			return hold;
			break;
	}

	return hold;
}

string make_fdesc()
{
    int *featurearr;
    int i;
    string fdesc;
    fdesc = "";
    featurearr = distinct_array(
        map_array(
            explode(
                crypt(file_name(TO),
                      "$1$")[4..6],
                ""),
            (:atoi(sprintf("%d",$1[0]))%$2:),
            sizeof(features)));
    for (i=0; i<sizeof(featurearr); ++i)
        fdesc+=" "+features[featurearr[i]];
    return fdesc;

}
