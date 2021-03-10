#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/claw";

int powerlevel, tier;
object mycaster;

void special_tier1(object wielder,object victim); // unique per essence
void special_tier2(object wielder,object victim); // essences are a repaint of this by default
void special_tier3(object wielder,object victim); // unique per essence
void special_tier4(object wielder,object victim); // essences are a repaint of this by default

void create() {
   ::create();
   set_name("eldritch claw");
   set_id(({"eldritch claw","claw","energy claw","claw of energy","gleaming claw","gleaming claw of energy","eldritch_weapon_xxx"}));
   set_short("%^RESET%^%^MAGENTA%^gl%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^am%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^ng cl%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^w of %^MAGENTA%^e%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^y%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This magical construct looks as though it would serve as a weapon of considerable %^RESET%^%^RED%^potency%^BOLD%^%^WHITE%^. "
"Instead of wood or metal, however, it is made purely of %^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^MAGENTA%^g"
"%^RESET%^%^MAGENTA%^y%^BOLD%^%^WHITE%^. Shaped like a claw, it bears three six-inch tines that each taper to a %^YELLOW%^razor-sharp %^BOLD%^%^WHITE%^point. "
"They spring from a flattened brace that rests around and across the hand, secured in place by seemingly nothing more than sheer manifestation of %^RESET%^"
"%^CYAN%^will%^BOLD%^%^WHITE%^.%^RESET%^\n");
   set_value(0);
   set_weight(0);
   set_wield((:TO,"wield_func":));
   set_hit((:TO,"hit_func":));
   set("no curse",1);
   set_prof_type("magic weapons");
   set_property("able to cast",1);
   powerlevel = 1;
   tier = 1;
}

void weapon_setup(object caster,int clevel) {
    int mychant;
    if(!objectp(caster)) return;
    mycaster = caster;
    powerlevel = clevel*10; // using this to parallel standardised in-game weapons
    if(powerlevel < 100) powerlevel = 100; // 10% minimum proc rate
    if(powerlevel < 250) powerlevel = 250; // 25% maximum proc rate to stay below dragon-drop weaponry on a 1h scale (35% on the 2h)
    mychant = clevel;
    if(mychant < 1) mychant = 1;
    if(mychant > (int)caster->query_level()) mychant = (int)caster->query_level(); // let's not let the weapon enchant & bonuses exceed what they can reasonably wield!
    mychant = (mychant-3) / 5; // slightly slower than the normal +1/5; should scale at 8/13/18/23/28/33/38.
    TO->set_property("enchantment",mychant);
    tier = mychant/2; // should give +1 at 13/23/33, caps at +3
    set_item_bonus("attack bonus",tier);
    set_item_bonus("damage bonus",tier);
    tier++; // using this afterwards for dice on specials!
}

int wield_func(){
   if(!objectp(mycaster)) return 0;
   if(ETO != mycaster) { // not your weapon!
     tell_object(ETO,"You try and grasp the claw, but your hand passes straight through it!");
     return 0;
   }
   return 1;
}

int hit_func(object targ){
    int rand;
    object *mywielded;
    string *myids;

    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    targ = ETO->query_current_attacker();
    if(!objectp(targ)) return 0;
    if(powerlevel < 1) return 0;

    if(random(1000) > powerlevel) return 1;
    rand = roll_dice(1,powerlevel);

// basic design: tier 1 and 3 are the same on all regardless of essence.
// tier 2 and 4 change according to the essence active at time of casting.
    switch(rand) {
      case 0..100: // 0 -> 10 clevel, tier 1
      special_tier1(ETO,targ);
      break;
      case 101..200: // 11 -> 20 clevel, tier 2
        special_tier2(ETO,targ);
      break;
      case 201..300: // 21 -> 30 clevel, tier 3
        special_tier3(ETO,targ);
      break;
      default: // 31+ clevel, tier 4
        special_tier4(ETO,targ);
      break;
    }
    return 1;
}

void special_tier2(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch claw f%^BOLD%^%^MAGENTA%^l%^BOLD%^%^WHITE%^a%^RESET%^%^MAGENTA%^sh%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^s brightly as it shreds "+victim->QCN+"'s flesh!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s claw f%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^as%^BOLD%^%^WHITE%^h%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^s brightly as it shreds your flesh!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The claw f%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^as%^BOLD%^%^WHITE%^h%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^s brightly as it shreds "+victim->QCN+"'s flesh!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^E%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^y surges through the eldritch claw as it plunges into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^E%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^y surges through "+wielder->QCN+"'s claw as it plunges into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^E%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^y surges through "+wielder->QCN+"'s claw as it plunges into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}

// non-essenced weapon has no second and fourth tier specials, only calls the tier below it.
// these will be overwritten for essenced weapons.
void special_tier1(object wielder,object victim) {
    special_tier2(wielder,victim);
}
void special_tier3(object wielder,object victim) {
    special_tier4(wielder,victim);
}

int save_me(string file){ return 1;}
int is_ok_wield() { return 1; }

void __ActuallyUnwield() {
   ::__ActuallyUnwield();
   tell_room(EETO,"%^RESET%^%^CYAN%^The gleaming claw shimmers and disappears.%^RESET%^");
   TO->remove();
}
