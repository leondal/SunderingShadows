// Azha street sweeper
// Code flagrantly stolen from Tristan's scavengers
// to clean up objects left over from carnage. Useful!
// Thorn@ShadowGate
// 960923
// Town of Azha
// sweeper.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

#define DESTRUCT_TIME 1000


#define RACES ({ "human", "half-elf", "half-elf", "dwarf", "human", \
                 "human", "half-elf", "human", "human", "human", \
                 "human", "human", "human" })

#define ADJ ({ "muscular", "massive", "rotund", "smelly", "dusty" \
               "heavy", "average", "average", "grubby" })                 

#define ACTS ({ "pushing a broom", "grumbling constantly", \
               "pushing a wheelbarrow", "carrying a broom" })                 

inherit "/d/azha/std/wander";

object room_from;

void create(){
	int i;
	string gender, act, short;
	object ob;
	
    ::create();
	i = sizeof(RACES);
	i = random(i);
	set_id( ({ "townsman", "sweeper", RACES[i] }) );
	set("race", RACES[i]);
	gender = "male";
	set_gender(gender);
	short = RACES[i];
	i = sizeof(ACTS);
	i = random(i);
	act = ACTS[i];
	i = sizeof(ADJ);
	i = random(i);
	short = ADJ[i]+" "+gender+" "+short+" "+act;
	set("short", "A "+short);
	set_name("A "+short);
    set_long(
@AZHA
  There are many ways to make a living in Azha, and this man has decided
to take up a life of cleaning up others' trash from the streets and
public buildings of the town.  Of course, many would look down upon
this job, but this man learned long ago from his cousins in the
Tharis forest that scavenging could be a very lucrative business, if
you knew where to look....
	%^BOLD%^CAUTION:%^RESET%^ He's a _very_ good sweeper...get my drift?
AZHA
        );
	set_class("ranger");
	set_property("full attacks",1);
	set_property("no death",1);
	level = 75;
	set_guild_level("cleric", level);
	set_spells( ({ "limb attack","call lightning" }));
	set_spell_chance(50);
	set_hd(level, 10);
	set_body_type("human");
	set_gender("male");
	set_exp(80);
	set_alignment(8);
	set_hp(1000);
	set_stats("strength",25);
	set_stats("intelligence",25);
	set_stats("dexterity",25);
	set_overall_ac(-14);
	ob=new(AEQUIPDIR+"iscimitar");
	ob->set_short("A beat-up, old scimitar");
	ob->set_long("This WAS a nice scimitar, maybe...possibly..."+
	"uhh, a long time ago...really.");
	ob->move(TO);
	command("wield sword in right hand");
	ob=new(AEQUIPDIR+"iscimitar");
	ob->set_short("A beat-up, old scimitar");
	ob->set_long("This WAS a nice scimitar, maybe...possibly..."+
	"uhh, a long time ago...really.");
	ob->move(TO);
	command("wield sword in left hand");
      add_money("gold",1500);
	set_emotes(7,({"%^BOLD%^%^RED%^The sweeper says%^RESET%^: "+
	"Stupid kids, leaving all their &$#@*&%! crap around!"}),0);
	if(clonep(TO)) call_out("selfDestruct", DESTRUCT_TIME);
}

void init(){
        object *livings;
        ::init();
        if(objectp(room_from) && ETO != room_from)
                room_from->remove();
        call_out("cleanem",1);
        livings = all_living(ETO);
        livings -= ({TO});
        if(livings == ({}))
                room_from = ETO;
        add_action("stop_steal","pp");
        add_action("stop_steal","steal");
}

cleanem(){
        object *inven, *livings;
        int i, j;

        inven = all_inventory(ETO);
        livings = all_living(ETO);

        inven -= ({livings});

        j = sizeof(inven);
        for(i = 0;i < j;i++)
                if(objectp(inven[i]) && !living(inven[i]))
                        inven[i]->remove();
        }

void set_paralyzed(int time,string message) { return 1;}


int stop_steal(string str){
	if(str && id(str)) {
		write(wrap("%^BOLD%^%^RED%^The sweeper says%^RESET%^: "+
		"YOU are going to steal from ME?  I think not."));
		kill_ob(TP,1);
		return 1;
	}
	return 0;
}

int selfDestruct() {
	object *inv;
	int x;

	inv = all_inventory(TO);
	for(x=0;x<sizeof(inv);x++) {
		if(!(inv[x]->remove())) destruct(inv[x]);
	}
	if(!(TO->remove())) destruct(TO);
	return 1;
}

	
	
