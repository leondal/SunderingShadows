
#include <std.h>
#include <move.h>

inherit POTION;


int uses, toggle;

void create() {
    ::create();
    set_name("blue vial");
	set_short("A kit of blue healing vials");
	set_id(({"blue","vial","potion","kit","kitxyz"}));
    set_long(
@OLI
	%^CYAN%^The pale blue liquid contained in this kit's vials
	is smooth but bitter. The case can hold many vials.
	you can <take # from kit> to split up the kit or you can
	<combine kit with kit #> to combine two kits.
OLI
	);
    set("color", "blue");
    set("effect_time", (random(4) * 60));
    uses = 1;
    toggle = 0;
    set_weight(2);
}
int do_effect() {
  if(!objectp(drinker)) return 1;
    tell_object(drinker, "The potion seems to cool your body.");
 	drinker->add_hp(roll_dice(2,4)+2);
    if(!uses) remove();
    return 1;
}

int do_wear_off() { return 0;}


int wear_off() {
        if(!uses){
        	do_wear_off() ;
        	destruct(this_object());
        }
        	return 1;
}

int quaff_potion(string str) {

    object vial;
    int temp ;

    if (!uses) {return 0; }
    if( id(str)){
        if(closed==1) {
            write("Perhaps you should open the potion vial first.\n");
            return 1;
        }

        write("You quickly quaff the draught from the "+query("color")+" potion.\n");
        tell_room(ETP,TPQCN+" drinks from a small vial.\n",TP);
        seteuid(getuid());
        drinker = this_player() ;
        uses--;
        set_weight(query_weight() - 2);
        ETO->add_encumbrance(-2);
        delay=5+(random(5));
        call_out("potion_effect",delay, drinker);

// Don't want anyone messing with this while it's in effect.
// this isn't the Right Way to do this but it's better than
// any equally easy alternative.

        make_empty(TP);
        return 1;
    }
    return 0;
}

void add_use(){
	uses += 1;
	}

int query_uses() { return uses;}

void set_uses(int num){
	uses = num;
	set_weight(2 * num);
}
	

string query_short(){
	string holder;
	
	holder = ::query_short();
	
	holder += " ["+uses+" left]";
	return holder;
}

string query_long(string str){
	string holder;
	
	holder = ::query_long(str);
	
	holder += "\t["+uses+" left]";
	return holder;
}

int restore_me(string file){
	int holder;
	
	holder = ::restore_me(file);
	
	set_weight(uses *2);
	return holder;
}

void toggle(){
	if(!toggle)
		toggle = 1;
	else
		toggle = 0;
}


void init(){
	::init();
	
   if(TP == ETO){
	add_action("split","take");
	add_action("split","split");
//
	add_action("combine","combine");
	add_action("combine","join");
}
}

int split(string str){
	object ob;
	int num;
	string word;
	
	if(!str) return 0;
	
	if(sscanf(str,"%d from %s",num,word) !=2) 
		return notify_fail("Syntax: take # from kit\n");
	
	if(num >= uses || num <= 0)
		return notify_fail("You may take from 1 to "+(uses-1)+" vials from this kit!\n");
	
	set_uses(uses-num);
	seteuid(getuid());
	ob=new(base_name(TO));
	ob->set_uses(num);
	ob->toggle();
	TP->add_encumbrance((-1)*2*num);
	ob->move(TP);
	ob->toggle();
	tell_room(ETP,"%^BLUE%^You see "+TPQCN+" take several vials from "+TP->query_possessive()+" kit.",TP);
	write("%^BLUE%^You remove "+num+" vials from your kit.");
	return 1;
}

int combine(string str){
	object ob;
	int num;
	string targ, dest;
	
	if(!str) return 0;
	
	if(sscanf(str,"%s with %s",targ,dest) !=2) 
		return notify_fail("Syntax: combine kit # with kit #\n");
	
	if(!id(targ))
		return 0;
	if(!ob=present(dest,TP))
		return notify_fail("No second kit.\n");
   if(ob==TO)
      return notify_fail("You can't do that.\n");
    if(!id(dest)) return 0;
	
	num = ob->query_uses();
	set_uses(query_uses()+num);
	seteuid(getuid());
     ob->remove();
	TP->add_encumbrance(2*num);
	tell_room(ETP,"%^BLUE%^You see "+TPQCN+" combine two kits of healing vials.",TP);
	write("%^BLUE%^You combine the two kits of healing vials.");
	return 1;
}
