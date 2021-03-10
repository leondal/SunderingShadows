#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/glaive";

int powerlevel, tier;
object mycaster;

void special_tier1(object wielder,object victim); // unique per essence
void special_tier2(object wielder,object victim); // essences are a repaint of this by default
void special_tier3(object wielder,object victim); // unique per essence
void special_tier4(object wielder,object victim); // essences are a repaint of this by default

void create() {
   ::create();
   set_name("eldritch glaive");
   set_id(({"eldritch glaive","glaive","energy glaive","glaive of energy","radiant glaive","radiant energy glaive","eldritch_weapon_xxx"}));
   set_short("%^RESET%^%^CYAN%^ra%^BOLD%^%^CYAN%^d%^RESET%^%^CYAN%^ia%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^t ene%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^gy %^CYAN%^g%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^v%^RESET%^%^CYAN%^e%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This magical construct looks as though it would serve as a weapon of considerable %^RESET%^%^RED%^potency%^BOLD%^%^WHITE%^. "
"Instead of wood or metal, however, it is made purely of %^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^CYAN%^g"
"%^RESET%^%^CYAN%^y%^BOLD%^%^WHITE%^. Shaped like a glaive, it rises from a long and narrow haft that must be at least six or seven feet long. From there, "
"it broadens and gains a %^YELLOW%^razor-sharp %^BOLD%^%^WHITE%^edge, forming a curved blade of %^RESET%^%^MAGENTA%^lethal %^BOLD%^%^WHITE%^purpose.%^RESET%^\n");
   set_weapon_prof("simple");   
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
    int mychant,mysize;
    if(!objectp(caster)) return;
    mycaster = caster;
    powerlevel = clevel*10; // using this to parallel standardised in-game weapons
    mysize = (int)caster->query_size()+1;
    set_size(mysize);
    if(powerlevel < 100) powerlevel = 100; // 10% minimum proc rate
    if(powerlevel < 350) powerlevel = 350; // 10% minimum proc rate    
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
     tell_object(ETO,"You try and grasp the glaive, but your hand passes straight through it!");
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
    tell_object(wielder,"%^RESET%^%^CYAN%^Your eldritch glaive f%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^sh%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^RESET%^%^CYAN%^brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^CYAN%^"+wielder->QCN+"'s glaive f%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^sh%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^RESET%^%^CYAN%^brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^CYAN%^The glaive f%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^sh%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^RESET%^%^CYAN%^brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^CYAN%^E%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^CYAN%^g%^RESET%^%^CYAN%^y races the length of the eldritch glaive as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^RESET%^%^CYAN%^E%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^CYAN%^g%^RESET%^%^CYAN%^y races the length of "+wielder->QCN+"'s glaive as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^CYAN%^E%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^CYAN%^g%^RESET%^%^CYAN%^y races the length of "+wielder->QCN+"'s glaive as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
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
   tell_room(EETO,"%^RESET%^%^CYAN%^The radiant glaive shimmers and disappears.%^RESET%^");
   TO->remove();
}
