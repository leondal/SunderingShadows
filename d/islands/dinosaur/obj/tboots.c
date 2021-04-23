// dino coded by hades 5/2/11
#include <std.h>
inherit ARMOUR;
int timer;

void create() {
   ::create();
   set_id(({"boots","leather boots","boots of stone","boot"}));
   set_name("%^RESET%^%^ORANGE%^Boo%^WHITE%^t%^ORANGE%^s of %^ORANGE%^Tremors%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^B%^WHITE%^one%^ORANGE%^ bo%^WHITE%^ot%^RESET%^s%^RESET%^");
   set_obvious_short("%^RESET%^A pair of %^ORANGE%^bone%^RESET%^ boots%^RESET%^");
   set_long(
    "%^ORANGE%^These boots are made of %^WHITE%^heavy bones%^ORANGE%^"+
	" from dinosaurs.  The souls are a large bit of %^WHITE%^bone"+
	"%^ORANGE%^ that is filed down to sit flush with the ground."+
	"  The boots are so large that only a giant could wear them."+
	"  Thick leather threads hold the different bits of bone "+
	"together.  The sides of the boots are very wide.  They bones "+
	"go down the ankles and end in points at the ground.  This makes"+
	" the wearers feet look almost like that of a %^GREEN%^dinosaur"+
	"%^ORANGE%^.  On the bottom of the shoes a thick %^WHITE%^brown "+
	"rune%^ORANGE%^ is etched and filled with a rocky pattern.%^RESET%^");
   set_lore("Dino island has had reports of strange magics across the"+
   " island.  These boots appear to be an example of such magics.  "+
   "Heavy dinosaurs often shake the ground as they walk.  The rune "+
   "on the bottom of the boots amplifies this effect.  One likely "+
   "could _stomp_ and cause the ground to shake.");
   set_property("lore difficulty",30);
   set_value(7000);
   set_type("clothing");
   set_size(3);
   set_property("enchantment",3);
   set_ac(0);
   set_weight(10);
   set_limbs(({"right foot","left foot"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   set_struck((:TO,"strikeme":));
}

int wearme(){
   if((int)ETO->query_level() < 20){
      tell_object(ETO,"You can't seem to figure out "+
         "how to lace these boots!");
      return 0;
   }
   tell_object(ETO,"%^GREEN%^You lace up the boots and your feet "+
      "look a bit like a dinosaur's feet.");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" boots make "+ETO->QO+
    " look a bit like a %^ORANGE%^dinosaur%^GREEN%^, not very attractive.",ETO);
    set("chabonus",-1);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^GREEN%^You pull your feet out of the uncomfortable boots.");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" looks better without these boots on.",ETO);
   set("chabonus",0);
   return 1;
      
}

int strikeme(int damage, object what, object who){

    if(!random(10))
    {
        tell_room(environment(query_worn()),"%^BOLD%^"+
           ""+ETOQCN+"'s boots are struck with a clank.",ETO);
        tell_object(ETO,"%^BOLD%^When the boots are struck,"+
                " the bone deflects some of the damage.");
        return damage/2;
    }
    return damage;
}

void init() {
   ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
   add_action("stomp_fun","stomp");
}


int stomp_fun(string str) {
   object *pplz;
   int i;
   pplz = all_living(EETO);
   if(ETO->query_bound() || ETO->query_unconscious()) {
     ETO->send_paralyzed_message("info",ETO);
     return 1;
   }
   if(!query_worn()) {
     write("Wearing the boots might help.\n");
     return 1;
   } 
   if (!str) {
     if(timer < time()) {

       timer = time() + 28800;
       tell_object(ETO,"You %^YELLOW%^stomp%^RESET%^ and a tremor"+
	   " shakes the area around you!\n");
       tell_room(EETO,""+ETO->QCN+" %^YELLOW%^stomps%^RESET%^ "+ETO->QP+" causing a"+
           " tremor that shakes the area around you!\n",ETO);
       new("/cmds/spells/t/_tremor")->use_spell(ETO,ETO,20,20,"cleric");
       return 1;
     }
     ETO->force_me("emote awkwardly stomps.");
     return 1;
   }
   write("Concentrate a little more clearly on the boots"+
   " - just <stomp> to use their power.\n");
   return 1;
}
