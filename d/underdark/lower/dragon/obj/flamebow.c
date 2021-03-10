#include <std.h>
#include <daemons.h>
#include "../lair.h"
inherit "/d/common/obj/lrweapon/longbow";

int OWNED, moteuse;
string *owners;
void set_active(int mystate);

void create(){
   ::create();
   set_name("longbow");
   set_active(0);
   set_short("%^RESET%^%^ORANGE%^Longbow of the %^BOLD%^%^BLACK%^Ni%^RESET%^g%^BOLD%^%^BLACK%^hth%^RESET%^u%^BOLD%^%^BLACK%^nt%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^'...and yet restless Ellevanora became, for she was not content with the purge "
"of the unliving from her home.  Peace was restored, but her soul ached for something more.  Further still "
"she ranged, across the rivers and over the mountains, leaving bandits and monsters lifeless in her wake.  "
"Words and gifts of thanks were offered for those she aided, but these did not content her.  Yet as the "
"trails carried her further north and west, tales reached her of those hidden pathways beneath the earth, "
"where night holds its eternal sway, and her kindred's dark cousins held their sway.  And so, she "
"descended beneath, never to again be seen in the surface realms.  Some say she still hunts there to this "
"day, her bow of silver flame lighting the passages beneath.  Others say the dark has long since taken "
"her...'%^RESET%^\n");
    set_property("lore difficulty",35);
    set_property("id difficulty",35);
    set_value(7400);
    set_prof_type("silver flame longbow");
    set_property("enchantment",5);
    while((int)TO->query_property("enchantment") != 5) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
    }
    set_property("magic",1);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_lrhit((:TO,"extra_lrhit":));
    set_item_bonus("attack bonus",3);
    set_item_bonus("damage bonus",3);
    set_item_bonus("sight bonus",3);
    set_property("no alter",1);
    owners = ({});
    set_ammo("%^BOLD%^%^WHITE%^silver flame arrow%^RESET%^");
    set_property("master weapon",1);
}

int use_shots(){ return 1; }
int query_shots(){ return -1; }
string query_ammo_type(){ return "silver flame arrow"; }

int wield_func(){
   int myflag, i;
   object myob, *mywielded;
   string thename;

   if(!userp(ETO)) return 1;
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this weapon.");
     return 0;
   }
   if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
     tell_object(ETO,"%^BOLD%^%^WHITE%^You reach out to grasp the bow, and the weapon already in your hand "
"seems to radiate with denial.  You find yourself unwilling even to lift the second weapon!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" reaches out to grasp the bow, but then hesitates, and "
"stops.",ETO);
     return 0;
   }
   tell_object(ETO,"%^YELLOW%^You string the longbow and take a firm grasp, and the wood in your hands bursts "
"into %^BOLD%^%^WHITE%^br%^RESET%^i%^BOLD%^%^WHITE%^ll%^YELLOW%^i%^BOLD%^%^WHITE%^ant %^YELLOW%^white flame!\n"
"%^BOLD%^%^WHITE%^You feel it may be effective to %^YELLOW%^shoot skywards%^BOLD%^%^WHITE%^.%^RESET%^");
   tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" strings the longbow and takes a firm grasp, and the wood in "+ETO->QP+
" hands bursts into %^BOLD%^%^WHITE%^br%^RESET%^i%^BOLD%^%^WHITE%^ll%^YELLOW%^i%^BOLD%^%^WHITE%^ant %^YELLOW%^white "
"flame!%^RESET%^",ETO);
   set_active(1);
   ETO->set_property("master weapon",1);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^YELLOW%^You release the blazing bow and the flames die abruptly, leaving the %^RESET%^p"
"%^BOLD%^%^WHITE%^a%^RESET%^le %^YELLOW%^weirwood completely unsinged.%^RESET%^");
   tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" releases the blazing bow and the flames die abruptly, leaving the "
"%^RESET%^p%^BOLD%^%^WHITE%^a%^RESET%^le %^YELLOW%^weirwood completely unsinged.%^RESET%^",ETO);
   set_active(0);
   ETO->set_property("master weapon",-1);
   return 1;
}

void set_active(int mystate) {
    if(mystate) {
      set_id(({"longbow","longbow of the nighthunter","bow","blazing longbow","white longbow","blazing white longbow","%^BOLD%^%^WHITE%^silver flame arrow%^RESET%^"}));
      set_obvious_short("%^RESET%^%^WHITE%^bl%^BOLD%^%^WHITE%^az%^RESET%^i%^YELLOW%^n%^RESET%^g wh%^BOLD%^%^WHITE%^it%^RESET%^e l%^BOLD%^%^WHITE%^o%^YELLOW%^n%^RESET%^gb%^BOLD%^%^WHITE%^o%^RESET%^w");
      set_long("%^BOLD%^%^BLACK%^This long curved shaft of wood seems at first too simple to serve as a %^RESET%^%^RED%^d"
"%^BOLD%^%^RED%^a%^RESET%^%^RED%^n%^RESET%^g%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^YELLOW%^o%^BOLD%^%^RED%^u%^RESET%^"
"%^RED%^s %^BOLD%^%^BLACK%^weapon, but in the hands of a skilled archer you suspect few other bows would serve "
"better than this.  Cut from a single piece of weirwood, the longbow is %^RESET%^sn%^BOLD%^%^WHITE%^ow%^RESET%^y-w"
"%^BOLD%^%^WHITE%^h%^RESET%^it%^BOLD%^%^WHITE%^e %^BOLD%^%^BLACK%^and smooth to the touch.  It bears a %^RESET%^"
"%^CYAN%^gentle %^BOLD%^%^BLACK%^curve to its center, and where it curls back upon itself at each end, it has been "
"bound with a band of %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r %^BOLD%^%^BLACK%^"
"metal.  The upper band secures a finely-woven %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^"
"%^WHITE%^r %^BOLD%^%^BLACK%^bowstring, while the lower band is raised from the wood to hook the loop at the end of "
"the bowstring and pull the weapon taut.  Both bands bear ancient glyphs in a curled and spidery script, and each "
"etched letter %^BOLD%^%^CYAN%^g%^BOLD%^%^GREEN%^l%^BOLD%^%^CYAN%^e%^BOLD%^%^GREEN%^a%^BOLD%^%^CYAN%^m%^BOLD%^"
"%^GREEN%^s %^BOLD%^%^BLACK%^with a life of its own.%^RESET%^\n");
    }
    else {
      set_id(({"longbow","longbow of the nighthunter","bow","weirwood longbow","weirwood bow","silverbound bow","silver-bound bow","silver-bound weirwood longbow","%^BOLD%^%^WHITE%^silver flame arrow%^RESET%^"}));
      set_obvious_short("%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r-b%^RESET%^o%^BOLD%^%^BLACK%^u%^RESET%^n%^BOLD%^%^WHITE%^d %^RESET%^w%^BOLD%^%^BLACK%^e%^RESET%^ir%^BOLD%^%^WHITE%^wo%^RESET%^od lo%^BOLD%^%^WHITE%^n%^RESET%^gb%^BOLD%^%^BLACK%^o%^RESET%^w%^RESET%^");
      set_long("%^BOLD%^%^BLACK%^This long curved shaft of wood seems at first too simple to serve as a %^RESET%^%^RED%^d"
"%^BOLD%^%^RED%^a%^RESET%^%^RED%^n%^RESET%^g%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^YELLOW%^o%^BOLD%^%^RED%^u%^RESET%^"
"%^RED%^s %^BOLD%^%^BLACK%^weapon, but in the hands of a skilled archer you suspect few other bows would serve "
"better than this.  Cut from a single piece of weirwood, the longbow is %^RESET%^sn%^BOLD%^%^WHITE%^ow%^RESET%^y-w"
"%^BOLD%^%^WHITE%^h%^RESET%^it%^BOLD%^%^WHITE%^e %^BOLD%^%^BLACK%^and smooth to the touch.  It bears a %^RESET%^"
"%^CYAN%^gentle %^BOLD%^%^BLACK%^curve to its center, and where it curls back upon itself at each end, it has been "
"bound with a band of %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r %^BOLD%^%^BLACK%^"
"metal.  The upper band secures a finely-woven %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^"
"%^WHITE%^r %^BOLD%^%^BLACK%^bowstring, while the lower band is raised from the wood to hook the loop at the end of "
"the bowstring and pull the weapon taut.  Both bands bear ancient glyphs in a curled and spidery script, and each "
"etched letter %^BOLD%^%^CYAN%^g%^BOLD%^%^GREEN%^l%^BOLD%^%^CYAN%^e%^BOLD%^%^GREEN%^a%^BOLD%^%^CYAN%^m%^BOLD%^"
"%^GREEN%^s %^BOLD%^%^BLACK%^with a life of its own.%^RESET%^\n");
    }
}

void init() {
   ::init();
   add_action("glitterdust_fun","shoot");
}

int glitterdust_fun(string str) {
    object *inven;
    int i;
    if(!str) return 0;
    if(str != "skywards") return 0;

    if(moteuse > time())
      return notify_fail("The bow has not yet recharged!\n");

    moteuse = time()+60;
    inven = all_living(ETP);
    inven -= ({ TP });

    tell_object(ETO,"%^BOLD%^%^WHITE%^You angle your bow abruptly and fire a gleaming arrow skywards, where it bursts to shed brilliant motes in a shower around you!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" angles "+ETO->QP+" bow abruptly and fires a gleaming arrow skywards, where it bursts to shed brilliant motes in a shower all around!%^RESET%^",ETO);

    if(sizeof(inven)) {
      for(i=0;i<sizeof(inven);i++){
        if(!inven[i]->query_property("faerie fire") && !inven[i]->query_true_invis() && !inven[i]->query_property("no detect")) new(OBJ"gleamingmote")->move(inven[i]);
      }
    }
    return 1;
}

int extra_lrhit(object targ){
    int rand, i;
    object *targetz;

    rand = roll_dice(1,10);
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    targ = ETO->query_current_attacker();
    if(!objectp(targ)) return 0;
    if(roll_dice(1,100) > 37) return roll_dice(1,4);

    if(rand > 0 && rand < 5) { // between 1 and 4 or 40%
	tell_object(ETO,"%^BOLD%^%^WHITE%^The flaming bow %^BOLD%^%^CYAN%^p%^BOLD%^%^WHITE%^ul%^BOLD%^%^CYAN%^s%^BOLD%^%^WHITE%^e"
"%^BOLD%^%^CYAN%^s %^BOLD%^%^WHITE%^as you loose a shot, and a tingling feeling runs through you, leaving you refreshed.%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"'s flaming bow %^BOLD%^%^CYAN%^p%^BOLD%^%^WHITE%^ul%^BOLD%^%^CYAN%^s"
"%^BOLD%^%^WHITE%^e%^BOLD%^%^CYAN%^s %^BOLD%^%^WHITE%^as "+ETO->QS+" looses a shot!%^RESET%^",ETO);
      TO->set_property("magic",1);
      ETO->do_damage("torso",roll_dice(8,4)*(-1));
      TO->set_property("magic",-1);
    }

    if(rand > 2 && rand < 6)  {// between 3 and 5 or 30%
	tell_object(ETO,"%^BOLD%^%^WHITE%^You shoot a fiery arrow directly at "+targ->QCN+", and as it hits it seems to turn "
"to %^RESET%^%^RED%^m%^BOLD%^%^RED%^o%^YELLOW%^l%^BOLD%^%^WHITE%^t%^BOLD%^%^RED%^e%^RESET%^%^RED%^n %^BOLD%^%^WHITE%^liquid, "
"spreading over "+targ->QP+" skin as it continues to burn!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" shoots a fiery arrow directly at you, and as it hits it seems to turn to "
"%^RESET%^%^RED%^m%^BOLD%^%^RED%^o%^YELLOW%^l%^BOLD%^%^WHITE%^t%^BOLD%^%^RED%^e%^RESET%^%^RED%^n %^BOLD%^%^WHITE%^liquid, "
"spreading over your skin as it continues to burn!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" shoots a fiery arrow directly at "+targ->QCN+", and as it hits it seems to "
"turn to %^RESET%^%^RED%^m%^BOLD%^%^RED%^o%^YELLOW%^l%^BOLD%^%^WHITE%^t%^BOLD%^%^RED%^e%^RESET%^%^RED%^n %^BOLD%^%^WHITE%^liquid, "
"spreading over "+targ->QP+" skin as it continues to burn!%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",roll_dice(3,10));
      tell_object(targ,"%^BOLD%^%^YELLOW%^The molten fire sears into your skin!%^RESET%^");
      new(OBJ"flamebow-tick")->move(targ);
    }

    if(rand > 4 && rand < 7) { // between 4 and 6 or 20%
	tell_object(ETO,"%^BOLD%^%^WHITE%^A blazing bolt of fire streaks forth from your bow and %^BOLD%^%^YELLOW%^b"
"%^BOLD%^%^RED%^u%^BOLD%^%^WHITE%^r%^BOLD%^%^RED%^s%^BOLD%^%^WHITE%^t%^BOLD%^%^YELLOW%^s %^BOLD%^%^WHITE%^upon impact "
"with "+targ->QCN+", shedding tongues of white flame in all directions!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^A blazing bolt of fire streaks forth from "+ETO->QCN+"'s bow and "
"%^BOLD%^%^YELLOW%^b%^BOLD%^%^RED%^u%^BOLD%^%^WHITE%^r%^BOLD%^%^RED%^s%^BOLD%^%^WHITE%^t%^BOLD%^%^YELLOW%^s "
"%^BOLD%^%^WHITE%^upon impact with you, shedding tongues of white flame in all directions!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^WHITE%^A blazing bolt of fire streaks forth from "+ETO->QCN+"'s bow and "
"%^BOLD%^%^YELLOW%^b%^BOLD%^%^RED%^u%^BOLD%^%^WHITE%^r%^BOLD%^%^RED%^s%^BOLD%^%^WHITE%^t%^BOLD%^%^YELLOW%^s "
"%^BOLD%^%^WHITE%^upon impact with "+targ->QCN+", shedding tongues of white flame in all directions!%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",roll_dice(3,10));
      targetz = ETO->query_attackers();
      targetz -= ({targ});
      if(sizeof(targetz)) {
        for(i=0;i<sizeof(targetz);i++) {
          if(!"daemon/saving_throw_d"->reflex_save(targetz[i],-25) && !"daemon/feat_d"->usable_feat(targetz[i],"evasion")) {
            tell_object(targetz[i],"%^BOLD%^%^YELLOW%^You are caught by the edge of the explosion!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^YELLOW%^"+targetz[i]->QCN+" is caught by the edge of the explosion!%^RESET%^",targetz[i]);
            targetz[i]->do_damage("torso",roll_dice(2,10));          
          }
        }
      }
    }

    if(rand > 6 && rand < 10) { // between 7 and 9 or 30%
	tell_object(ETO,"%^BOLD%^%^WHITE%^As the bow is drawn, not one but two d%^RESET%^az%^BOLD%^%^WHITE%^zl%^RESET%^i"
"%^BOLD%^%^WHITE%^ng arrows of flame spring into being!%^RESET%^");
	if(sizeof(ETO->query_attackers())) ETO->execute_attack();
    }

    if(rand == 10) { // blind/stun on 10% only
	tell_object(targ,"%^BOLD%^%^WHITE%^A %^YELLOW%^dazzling %^BOLD%^%^WHITE%^arrow leaps forth from the bow, "
"its incandescent brilliance momentarily blinding you!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^WHITE%^A %^YELLOW%^dazzling %^BOLD%^%^WHITE%^arrow leaps forth from the bow, its "
"incandescent brilliance nearly blinding you!%^RESET%^",targ);
      targ->set_paralyzed(roll_dice(5,5)+25,"%^BOLD%^%^WHITE%^You're trying to blink spots away from your eyes!%^RESET%^");
      if(!"daemon/saving_throw_d"->reflex_save(targ,-30)) targ->set_temporary_blinded(2);
    }
}

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}