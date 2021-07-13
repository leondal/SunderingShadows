// updated bonuses to meet current standards. N, 24/1/20.
#include <std.h>
inherit "/d/common/obj/armour/shield";

int OWNED;
string *owners;
void set_mydesc(int worn);

void create(){
   ::create();
   set_name("platinum shield");
   set_id(({"shield","shard shield","shield of shards","platinum shield","shield of platinum shards","shield of jagged platinum shards","barrier","razorstorm barrier","Razorstorm Barrier"}));
   set_short("%^BOLD%^%^BLACK%^R%^RESET%^a%^BOLD%^%^WHITE%^z%^CYAN%^o%^RESET%^r%^MAGENTA%^s%^RESET%^t%^BOLD%^%^WHITE%^o%^BLACK%^r%^RESET%^m %^BOLD%^%^BLACK%^B%^YELLOW%^a%^WHITE%^r%^BLACK%^r%^RESET%^%^CYAN%^i%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^");
   set_mydesc(0);
   set_lore("%^BOLD%^%^WHITE%^Sylana Hawkspur's final demise was met many years later, at the hands of a group of "
"illithids upon the island of Laerad.  The lady knight had ventured to the dangerous caverns there many times previous, "
"and while never having posed any threat, it seemed that now the psionic monsters had unleashed something far more "
"horrific than themselves upon the world.  From the depths came a terrifying abomination, a creation cast out when the "
"illithids could no longer control it; an insane beast known as a vampire illithid.  It lashed out at her, and resolutely "
"she held her ground, dealing grievous wounds upon it.  Finally, in its last breath the madness and pain were too much to "
"bear, and as the creature died it unleashed such a great concussion of psionic energies that it literally tore Sylana "
"apart.\n\n%^BOLD%^%^WHITE%^Her remains were found many years later by a band of roving adventurers.  Among them was "
"Sylana's shield, shredded nearly to pieces but still retaining enough latent psionic energy to hold its pieces together"
".  But such twisted magic was said to have had strange effects upon the piece of armor...\n\n\n\t%^BOLD%^%^CYAN%^Taken "
"from the memoirs of house Hawkspur, 578 SG.");
   set_property("lore difficulty",35);
   set_property("id difficulty",35);
   set_value(8500);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("spell damage resistance",30);
   set_item_bonus("shieldMiss",40);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   set_property("no alter",1);
   owners = ({});
}

void init() {
   ::init();
   if(!TO->query_worn()) set_mydesc(0);
}

int wear_fun() {
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this shield.");
     return 0;
   }
   tell_room(EETO,"%^BOLD%^%^BLACK%^A low %^RESET%^%^CYAN%^hum %^BOLD%^%^BLACK%^arises from the %^RESET%^%^MAGENTA%^"
"glowing orb %^BOLD%^%^BLACK%^as "+ETO->QCN+" lifts the shield, and the razor shards of %^WHITE%^pla%^CYAN%^t%^WHITE%^"
"inum %^BLACK%^begin to whirl.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^A low %^RESET%^%^CYAN%^hum %^BOLD%^%^BLACK%^arises from the %^RESET%^%^MAGENTA%^"
"glowing orb %^BOLD%^%^BLACK%^as you lift the shield, and the razor shards of %^WHITE%^pla%^CYAN%^t%^WHITE%^inum %^BLACK%^"
"begin to whirl.%^RESET%^");
   set_mydesc(1);
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^BLACK%^The low %^RESET%^%^CYAN%^hum %^BOLD%^%^BLACK%^fades to silence as the spinning "
"shards settle back into place.%^RESET%^");
   set_mydesc(0);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(3)){
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" raises "+ETO->QP+" shield to deflect "+who->QCN+"'s attack, and the "
"whirling shards of %^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^z%^RESET%^o%^BOLD%^%^WHITE%^r-s%^RESET%^h%^BOLD%^%^BLACK%^a"
"%^RESET%^r%^BOLD%^%^WHITE%^p %^BLACK%^metal shear into "+who->QP+" flesh!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^BOLD%^%^BLACK%^You raise your shield to deflect "+who->QCN+"'s attack, and the whirling shards "
"of %^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^z%^RESET%^o%^BOLD%^%^WHITE%^r-s%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^"
"%^WHITE%^p %^BLACK%^metal shear into "+who->QP+" flesh!%^RESET%^");
     tell_object(who,"%^BOLD%^%^BLACK%^"+ETO->QCN+" raises "+ETO->QP+" shield to deflect your attack, and the whirling "
"shards of %^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^z%^RESET%^o%^BOLD%^%^WHITE%^r-s%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^r"
"%^BOLD%^%^WHITE%^p %^BLACK%^metal shear painfully into your flesh!%^RESET%^");
     who->do_damage("left arm",random(15)+35);
     return 0;
   }
   return damage;
}

void set_mydesc(int worn) {
   if(!worn) {
     TO->set_long("%^RESET%^Quite an oddly formed piece of armor, the primary portion consists of a curved plate of "
"polished %^BOLD%^%^WHITE%^pla%^CYAN%^t%^WHITE%^inum %^RESET%^that gleams with a perfect finish.  A grip lies upon the "
"underside, allowing it to be raised and held as a shield.  However, the edges of the plate seem to have been roughly "
"sheared away, leaving %^BOLD%^%^BLACK%^j%^YELLOW%^a%^BOLD%^%^BLACK%^g%^RESET%^g%^RED%^e%^BOLD%^%^BLACK%^d %^RESET%^"
"ridges and points that protrude in all directions.  It is surrounded by a good many secondary shards, some wide and "
"some narrow, and many with %^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^z%^RESET%^o%^BOLD%^%^WHITE%^r-s%^RESET%^h"
"%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^p %^RESET%^tips, though fortunately these seem to sit locked together in "
"such a way as not to leave dangerous angles protruding forth.  It remains a mystery just how they are held in place, as "
"there is no visible adhesive or attachment to keep them together, yet they resist any attempts to pull them free.  The "
"only hint at some sort of forcefield or magnetism is the softly %^MAGENTA%^gl%^BOLD%^owi%^RESET%^%^MAGENTA%^ng %^RESET%^"
"orb embedded within the centre of the main plate, which never grows dim.\n");
     TO->set_obvious_short("%^BOLD%^%^WHITE%^shield of j%^RESET%^a%^BOLD%^%^BLACK%^g%^BOLD%^%^WHITE%^g%^YELLOW%^e%^WHITE%^d pla%^CYAN%^t%^WHITE%^inum shards%^RESET%^");
   }
   else {
     TO->set_long("%^RESET%^Quite an oddly formed piece of armor, the primary portion consists of a curved plate of "
"polished %^BOLD%^%^WHITE%^pla%^CYAN%^t%^WHITE%^inum %^RESET%^that gleams with a perfect finish.  A grip lies upon the "
"underside, allowing it to be raised and held as a shield.  However, the edges of the plate seem to have been roughly "
"sheared away, leaving %^BOLD%^%^BLACK%^j%^YELLOW%^a%^BOLD%^%^BLACK%^g%^RESET%^g%^RED%^e%^BOLD%^%^BLACK%^d %^RESET%^"
"ridges and points that protrude in all directions.  It is surrounded by a whirling storm of secondary shards, some wide "
"and some narrow, and many with %^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^z%^RESET%^o%^BOLD%^%^WHITE%^r-s%^RESET%^h"
"%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^p %^RESET%^tips that orbit the main plate in a deadly swarm.  A low "
"%^CYAN%^hum %^RESET%^emanates from the armor, hinting at some form of forcefield or magnetism that prevents the "
"fragments from flying apart.  The sound seems to originate from the softly %^MAGENTA%^gl%^BOLD%^owi%^RESET%^%^MAGENTA%^"
"ng %^RESET%^orb embedded within the centre of the main plate, which never grows dim.\n");
     TO->set_obvious_short("%^BOLD%^%^WHITE%^shield of wh%^RESET%^i%^CYAN%^r%^BOLD%^%^WHITE%^li%^CYAN%^n%^WHITE%^g pla%^CYAN%^t%^WHITE%^inum shards%^RESET%^");
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
