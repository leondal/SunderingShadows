/*  Mundanoid   by Killashandra  */
// fix per bug report by Saide/Styx 12/25/03, last change 8/20/01
// changed this one to inherit the other and set moving & nogo instead of the wander inherit

#include <std.h>
#include "/d/stella/short.h"
inherit "/d/stella/mon/mund_nw.c";

void create() {
   ::create();
   set_speed(20);
   set_nogo( ({ "/d/stella/rooms/garden1" }) );
}


/*
// This shouldn't be here, should it?  Saide 
// *Styx* - yes, it would keep them from being able to be paralyzed, doubtless intended
void set_paralyzed(int time,string message){return 1;}

int moves();

int hd,xx,hdlev;

void create() {
    :: create();
    set_name("Mundanoid");
    set_id(({
      "mundanoid", "humanoid", "mund"
      }));
    set_short("%^RESET%^%^CYAN%^Mundanoid%^RESET%^");
    set_attacks_num(3);
    hd=random(20)+5;
    set_property("no bows",1);
    if (hd<10) hdlev=1;
        else if (hd<20) {hdlev=2;}
        else if (hd<30) {hdlev=3;}
        else if (hd<40) {hdlev=4;}
        else hdlev=5;
    if (hdlev == 1)
        set_long(
            "%^RESET%^%^CYAN%^This creature appears human in form "
	    "except for its dark grey skin and deep black eyes.");
    else if (hdlev == 2)
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "There are flashes of colour in its grey skin.%^RESET%^");
    else if (hdlev == 3)
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "Its grey skin shimmers with colourful highlights.%^RESET%^");
    else if (hdlev == 4)
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "Its skin seems to shimmer with all the colours of the rainbow.  "
      "Its eyes are glowing!%^RESET%^");
    else {
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "Its skin seems to shimmer with all the colours of the rainbow "
	    "and glows as if lit from within.%^RESET%^");
    set_attacks_num(6);
	}
    set_gender("male");
    set_alignment(9);
    set_size(2);
    set_class("fighter");
    set_hd(hd,0);
    set_mlevel("fighter", hd);
    set_level(hd);
    set_attack_limbs(({"right hand", "left hand"}) );
    set_base_damage_type("bludgeoning");
    set_damage(2,6);
    set_overall_ac(5-(hd/3));
    set_property("no bump",1);
    set_property("no steal",1);
    set_max_hp(150+random(hd*10));
    set_hp(query_max_hp());
    set_exp(hd*750);
    set_body_type("human");
    set_race("mundanoid");
    set_stats("strength",22);
    set_stats("constitution",20);
    set_stats("dexterity",18);
    set_stats("wisdom",18);
    set_stats("intelligence",14);
    set_stats("charisma",5);
    set("aggressive","agg_fun");
    set_funcs(({"moves","steal_magic"}));
    set_func_chance(50);
    set_emotes(5, ({
        "%^CYAN%^The mundanoid looks at you hungrily!%^RESET%^",
        "%^BLUE%^The mundanoid's eyes glow briefly.%^RESET%^",
    }),1);
}

void changes(object targ){

    if (hd<10) xx=1;
    else if (hd<20) {xx=2;}
    else if (hd<30) {xx=3;}
    else if (hd<40) {xx=4;}
    else if (hd<50) {xx=5;}
    else if (hd<60) {xx=6;}
    else if (hd<70) {xx=7;}
    else {xx=8;}

    if (xx==hdlev) return 1;
    else hdlev = xx;

    switch(xx) {
    case 1:
    	tell_object(targ,
    	    "%^BLUE%^The Mundanoid's skin seems to lighten in colour!%^RESET%^");
    	tell_room(environment(targ),
    	    "%^BLUE%^The Mundanoid's skin seems to lighten in colour!%^RESET%^",targ);
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "It has light grey skin and dark grey eyes.%^RESET%^");
	return;
     case 2:
    	tell_object(targ,
    	    "%^CYAN%^You see flashes of colour on the Mundanoid's skin!%^RESET%^");
    	tell_room(environment(targ),
    	    "%^CYAN%^You see flashes of colour on the Mundanoid's skin!%^RESET%^",targ);
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "There are flashes of colour in its grey skin.%^RESET%^");
    set_attacks_num(4);
	return;
     case 3:
    	tell_object(targ,
    	    "%^RED%^The Mundanoid's skin begins to shimmer!%^RESET%^");
    	tell_room(environment(targ),
    	    "%^RED%^The Mundanoid's skin begins to shimmer!%^RESET%^",targ);
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "Its grey skin shimmers with colourful highlights.%^RESET%^");
	return;
     case 4:
    	tell_object(targ,"%^ORANGE%^You can see rainbow hues in the Mundanoid's skin!%^RESET%^");
    	tell_room(environment(targ),
    	    "%^ORANGE%^You can see rainbow hues in the Mundanoid's skin!%^RESET%^",targ);
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "Its skin seems to shimmer with all the colours of the rainbow.%^RESET%^");
    set_attacks_num(5);
	return;
     case 5:
    	tell_object(targ,
    	    "%^WHITE%^The Mundanoid's eyes are glowing!%^RESET%^");
    	tell_room(environment(targ),
    	    "%^WHITE%^The Mundanoid's eyes are glowing!%^RESET%^",targ);
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "Its skin seems to shimmer with all the colours of the rainbow.  "
      "Its eyes are glowing!%^RESET%^");
    set_attacks_num(5);
	return;
     case 6:
    	tell_object(targ,
    	    "%^YELLOW%^The Mundanoid seems lit by an internal glow!%^RESET%^");
    	tell_room(environment(targ),
    	    "%^YELLOW%^The Mundanoid seems lit by an internal glow!%^RESET%^",targ);
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears human in form.  "
	    "Its skin seems to shimmer with all the colours of the rainbow "
	    "and glows as if lit from within.%^RESET%^");
    set_attacks_num(5);
	return;
     case 7:
    	tell_object(targ,
    	    "%^GREEN%^The Mundanoid has grown into a giant!%^RESET%^");
    	tell_room(environment(targ),
    	    "%^GREEN%^The Mundanoid has grown into a giant!%^RESET%^",targ);
	TO->set_size(3);
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears to be a giant humananoid.  "
	    "Its skin seems to shimmer with all the colours of the rainbow "
	    "and glows as if lit from within.%^RESET%^");
    set_attacks_num(6);
 	return;
    case 8:
    	tell_object(targ,
    	    "%^CYAN%^You are blinded by the chaotic swirl of colour that was once a Mundanoid!%^RESET%^");
    	tell_room(environment(targ),
    	    "%^CYAN%^You are blinded by the chaotic swirl of colour that was once a Mundanoid!%^RESET%^",targ);
	set_long(
	    "%^RESET%^%^CYAN%^This creature appears to be a giant humananoid.  "
	    "Its skin is a chaotic swirl of colour and glows as if lit from within.%^RESET%^");
    set_attacks_num(7);
	return;
      }
    return;
}


int agg_fun(object ob) {

    object *inv = deep_inventory(TP);
    int xx, newac, newhd, numinv = sizeof(inv);
    int hits = query_hp();

    if (numinv == 0) return 1;

    xx = random(numinv);
    if(inv[xx]->query_property("plot_item") || inv[xx]->query_property("soulbound")) return 1;
    if((inv[xx]->query_property("enchantment") && inv[xx]->query_property("enchantment")>0) ||
	inv[xx]->query_property("magic")  ||
	((member_array("ring",inv[xx]->query_id()) >= 0)&&(member_array("onyx",inv[xx]->query_id())==-1)) ||
	(member_array("well",inv[xx]->query_id()) >= 0) ||
	(member_array("staff",inv[xx]->query_id()) >= 0) ||
	(member_array("wand",inv[xx]->query_id()) >= 0) ||
        (member_array("key",inv[xx]->query_id()) >= 0))
     {
        tell_object(TP, "%^BOLD%^%^CYAN%^The Mundanoid reaches out and touches your "+inv[xx]->query_name()+ "!! It turns to ash as the magic is drained out of it!%^RESET%^" );
        tell_room(environment(TP),
          "%^BOLD%^%^CYAN%^The Mundanoid reaches out and touches "+TPQCN+"'s "
	  +inv[xx]->query_name()+"!! It turns to ash as the magic is drained from it!%^RESET%^",TP);
        if (inv[xx]->query_property("enchantment")) {
	  newhd = inv[xx]->query_property("enchantment");
          if(newhd < 1) newhd = 1;
	  newhd = newhd*10;
        }
        else if (inv[xx]->query_property("enhancement")){
	  newhd = inv[xx]->query_property("enhancement");
          if(newhd < 1) newhd = 1;
	  newhd = newhd*10;
      }
      else newhd = 20;

      hd += newhd;
      if (hd>80) hd = 80;
      newac = 0-(hd/2);
      set_overall_ac(newac);
      set_exp(hd*1250);
    set_hd(hd,0);
      set_level(hd);
      set_hp(hits+150);
      TO->add_hp(newhd*5);
      inv[xx]->remove();
      changes(TP);
      return 1;
    }
    return 1;
}

int do_damage(string limb, int dam) {
    object prev = previous_object();
    object targ = TO->query_current_attacker();
    string base = base_name(prev);
    string *verbs, verb;
    object *weap;
    int hits = query_hp();
    int newhd,newac,xx,enc,x;

    enc = 0;
    if(targ){
      weap = targ->query_wielded();
      for(x=0;x<sizeof(weap);x++) {
	enc += weap[x]->query_property("enchantment");
      }
    }
    verbs = explode(base,"_");

    if (sizeof(verbs)>1) verb = verbs[1];
    else verb = verbs[0];

    if ((base[0..4] == "/cmds") 
        && (member_array(verb,({"demonbolt","rebuke"})) != -1))
      enc = 3;

    if (!prev->is_spell() && !prev->query_property("magic")
	&& !enc ) return ::do_damage(limb,dam);

    if (prev->is_spell()) {
      newhd = prev->query_spell_level();
    }
    if (prev->query_property("magic")){
      newhd = dam/5;
    }
    if (enc){
      newhd = enc*2;
    } else return ::do_damage(limb,dam);

    if (hd>80) hd = 80;

    if(newhd < 1) newhd = 1;
    hd += newhd;
    newac = 0 - (hd/2);
    set_overall_ac(newac);
      set_exp(hd*1250);
     set_hd(hd,0);
    set_level(hd);
      set_hp(hits+150);
// changed this to use the add_hp function - was using heal and bugging 
//   seems to work fine now - heal(int) function only for players?  - Saide
//      TO->heal(newhd*5);
// Note by Styx, I think heal should work but this does seem to fix it *shrug*
    TO->add_hp(newhd*5);
    changes(targ);
    return 1;
}

int steal_magic() {
    object targ = TO->query_current_attacker();
    object *inv = deep_inventory(targ);
    int xx, newac, newhd, numinv = sizeof(inv);
    int hits = query_hp();

    if (numinv == 0) return 1;

    xx = random(numinv);
    if(inv[xx]->query_property("plot_item") || inv[xx]->query_property("soulbound")) return 1;
    if((inv[xx]->query_property("enchantment") && inv[xx]->query_property("enchantment")>0) ||
	inv[xx]->query_property("magic") ||
	((member_array("ring",inv[xx]->query_id()) >= 0)&&(member_array("onyx",inv[xx]->query_id())==-1)) ||
	(member_array("well",inv[xx]->query_id()) >= 0) ||
	(member_array("staff",inv[xx]->query_id()) >= 0) ||
	(member_array("wand",inv[xx]->query_id()) >= 0) ||
	(member_array("key",inv[xx]->query_id()) >= 0))
      {
      tell_object(targ,
          "%^BOLD%^%^CYAN%^The Mundanoid reaches out and touches your "+inv[xx]->query_name()+
	  "!! IT turns to ash as the magic is stolen from it!%^RESET%^");
      tell_room(environment(targ),
          "%^BOLD%^%^CYAN%^The Mundanoid reaches out and touches "+targ->QP+" "
	  +inv[xx]->query_name()+"!! IT turns to ash, as the magic is stolen "
	  "from it!%^RESET%^",targ);
      if (inv[xx]->query_property("enchantment")) {
	newhd = inv[xx]->query_property("enchantment");
	newhd = newhd*10;
      }
      else if (inv[xx]->query_property("enhancement")){
	newhd = inv[xx]->query_property("enhancement");
	newhd = newhd*10;
      }
      else newhd = 20;

    if(newhd < 1) newhd = 1;
      hd += newhd;
      if (hd>80) hd = 80;
      newac = 0-(hd/2);
      set_overall_ac(newac);
      set_exp(hd*1250);
    set_hd(hd,0);
      set_level(hd);
      inv[xx]->remove();
      set_hp(hits+150);
//  converting the heal here too *Styx*
//     TO->heal(newhd*5);
      TO->add_hp(newhd*5);
      changes(targ);
      return 1;
    }
    moves();
    return 1;
}

int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();

    if (hd<10) xx=1;
    else if (hd<20) {xx=2;}
    else if (hd<30) {xx=3;}
    else if (hd<40) {xx=4;}
    else if (hd<50) {xx=5;}
    else if (hd<60) {xx=6;}
    else if (hd<70) {xx=7;}
    else {xx=8;}
    switch(xx) {
    case 1:
    	tell_object(targ, "%^BLUE%^The Mundanoid lands a solid blow with its fist.%^RESET%^");
    	tell_room(environment(targ), "%^GREEN%^The Mundanoid lands a solid blow on "
	    +targ->query_cap_name()+"%^RESET%^",targ);
    	targ->do_damage("head",roll_dice(2,8));
    	return 1;
    case 2:
    	tell_object(targ,"%^RED%^The Mundanoid throws a massive fireball at you!%^RESET%^");
    	tell_room(environment(targ),"%^RED%^The Mundanoid throws a massive fireball at "
	    +targ->query_cap_name()+"%^RESET%^",targ);
	if("daemon/saving_d"->saving_throw(ob,"spell")) {
            tell_object(targ,"%^RED%^The fireball hits you!%^RESET%^");
            tell_room(environment(targ),"%^RED%^The fireball hits "
                +targ->query_cap_name()+"!%^RESET%^",targ);
            targ->do_damage("torso",roll_dice(10,6));
    	  } else {
            tell_object(targ,"%^MAGENTA%^You avoid the worst of the fireball!%^RESET%^");
            tell_room(environment(targ), "%^MAGENTA%^"+targ->query_cap_name()+
                " avoids the worst of the fireball!%^RESET%^",targ);
	    targ->do_damage("torso",roll_dice(5,6));
    	}
	return 1;
    case 3:
        new("/cmds/spells/c/_cone_of_cold.c")->use_spell(TO,targ->query_name(),40,100,"mage");
	return 1;
    case 4:
        new("/cmds/spells/c/_chain_lightning.c")->use_spell(TO,targ->query_name(),40,100,"mage");
	return 1;
    case 5:
        tell_object(targ, "%^BOLD%^%^WHITE%^The Munanoid's eyes are so "
	    "bright that they blind you!%^RESET%^");
        tell_room(environment(targ), "%^BOLD%^%^WHITE%^"+targ->QCN+
	    " is blinded by the Mundanoid's glowing eyes!%^RESET%^",targ);
        targ->set_paralyzed(30+random(20),
            "%^WHITE%^%^BOLD%^You can't see anything!%^RESET%^");
	return 1;
    case 6:
        new("/cmds/spells/m/_monster_summoning_vii.c")->use_spell(TO,targ->query_name(),70,100,"mage");
	return 1;
    case 7:
        new("/cmds/spells/i/_ice_storm.c")->use_spell(TO,targ->query_name(),70,100,"mage");
	return 1;
    case 8:
        new("/cmds/spells/f/_finger_of_death.c")->use_spell(TO,targ->query_name(),70,100,"mage");
	return 1;
      }
    return 1;
}
*/