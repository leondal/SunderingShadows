//Octothorpe (1/10/09)
//Proposed Phantasmic Plate Update
//Appearance change based upon Robes of the Magi
///d/antioch/ruins/obj/robes.c

#include <std.h>
inherit "/d/common/obj/armour/fullplate";

string owner;

void create(){
   ::create();
   set_name("phantasmic plate");
   set_id(({"phantasmic plate","armour","phantasmic plate armour","plate","armor","phantasmic","phantasmicplate"}));
   set_obvious_short("%^BOLD%^%^YELLOW%^A suit of reflective full "+
      "plate%^RESET%^");
   set_short("%^BOLD%^%^YELLOW%^Ph%^ORANGE%^a%^YELLOW%^nt%^ORANGE%^a"+
      "%^YELLOW%^sm%^ORANGE%^i%^YELLOW%^c F%^ORANGE%^u%^YELLOW%^ll Pl"+
      "%^ORANGE%^a%^YELLOW%^t%^ORANGE%^e%^RESET%^");
   set_long("%^BOLD%^%^YELLOW%^This armor is constructed entirely of "+
      "thousands of half-inch squares, seemingly bound together by no "+
      "discernable method. The squares are made of an unknown material "+
      "that appears to be an amalgam of metal and glazed ceramic. The "+
      "g%^ORANGE%^o%^YELLOW%^ld%^ORANGE%^e%^YELLOW%^n squares are highly "+
      "reflective, creating thousands of tiny mirrors over the surface "+
      "the armor. Although it readily reflects the environment around "+
      "it, this plate certainly does not hail from this plane.%^RESET%^");
   set_lore("Rumor has it that this incredible suit of armor was found "+
      "adrift on the Astral Plane by the Kinnesarudan agent Magus Prime. "+
      "The armor forms a symbiotic relationship with its wearer, and "+
      "essentially becomes an extension of the wearer's will. Only "+
      "those of near legenadary power are able to summon the mental "+
      "discipline necessary to will the shards to encase their body "+
      "with this magnificent armor. As the shards fuse together to "+
      "reform the plate, they change color to reflect the ethos of the "+
      "wearer. Supposedly the golden color that the armor adopted for "+
      "Intruder, is a reflection of his immense immortal power and "+
      "hubris, and is unattainable for a mortal.");
   set_value(20000);
   set_size(3);
   set_property("enchantment",5);
   set_property("magic resistance",10);
   set_property("fortitude",3);
   set_property("reflex",3);
   set_property("will",3);
   set_property("lore difficulty",18);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun(){
   if(interactive(TP) && owner != (string)TPQN){
      tell_object(ETO,"%^BOLD%^This suit of armor is not bound to "+
         "your lifeforce!%^RESET%^");
      return 0;
   }
   if((int)ETO->query_lowest_level() < 35){
      tell_room(EETO,"%^BOLD%^The full plate flies apart into a "+
         "million spinning shards that begin to reassemble around "+
         ""+ETOQCN+", but after a split second they violently spin "+
         "out of orbit around "+ETO->QO+"!%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^The full plate flies apart into a "+
         "million spinning shards that begin to reassemble around "+
         "you, but you lack the willpower to control the shards, and "+
         "watch helplessly as they fly away from you!%^RESET%^");
      return 0;
   }
   if(base_name(ETO) == "/d/attaya/mon/intruder"){
      tell_room(EETO,"%^BOLD%^The full plate flies apart into a "+
         "million %^BOLD%^%^YELLOW%^g%^ORANGE%^o%^YELLOW%^ld%^ORANGE%^"+
         "e%^YELLOW%^n %^WHITE%^spinning shards, and is reassembled "+
         "around Intruder!%^RESET%^",ETO);
      set_obvious_short("%^BOLD%^%^YELLOW%^A suit of r%^WHITE%^e"+
         "%^YELLOW%^fl%^WHITE%^e%^YELLOW%^ct%^WHITE%^i%^YELLOW%^v"+
         "%^WHITE%^e %^YELLOW%^full plate%^RESET%^");
      set_short("%^BOLD%^%^YELLOW%^Ph%^ORANGE%^a%^YELLOW%^nt%^ORANGE%^"+
         "a%^YELLOW%^sm%^ORANGE%^i%^YELLOW%^c F%^ORANGE%^u%^YELLOW%^ll "+
         "Pl%^ORANGE%^a%^YELLOW%^t%^ORANGE%^e%^RESET%^");
      set_long("%^BOLD%^%^YELLOW%^This armor is constructed entirely "+
         "of thousands of half-inch squares, seemingly bound together "+
         "by no discernable method. The squares are made of an unknown "+
         "material that appears to be an amalgam of metal and glazed "+
         "ceramic. The g%^ORANGE%^o%^YELLOW%^ld%^ORANGE%^e%^YELLOW%^n "+
         "squares are highly reflective, creating thousands of tiny "+
         "mirrors over the surface the armor. Although it readily "+
         "reflects the environment around it, this plate certainly "+
         "does not hail from this plane.%^RESET%^");
      return 1;
   }
   if(ALIGN->is_good(ETO)){
      tell_room(EETO,"%^BOLD%^The full plate flies apart into a "+
         "million white spinning shards, and is reassembled around "+
         ""+ETOQCN+"!%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^The full plate flies apart into a "+
         "million white spinning shards, and is reassembled around "+
         "you!%^RESET%^");
      set_short("%^BOLD%^%^WHITE%^Phantasmic Full Plate%^RESET%^");
      set_obvious_short("%^BOLD%^%^WHITE%^A suit of r%^RESET%^e%^BOLD%^fl"+
         "%^RESET%^e%^BOLD%^ct%^RESET%^i%^BOLD%^v%^RESET%^e %^BOLD%^"+
         "full plate%^RESET%^");
      set_long("%^BOLD%^This armor is constructed entirely of "+
         "thousands of half-inch squares, seemingly bound together "+
         "by no discernable method. The squares are made of an "+
         "unknown material that appears to be an amalgam of metal "+
         "and glazed ceramic. The bright white squares are highly "+
         "reflective, creating thousands of tiny mirrors over the "+
         "surface the armor. Although it readily reflects the "+
         "environment around it, this plate certainly does not hail "+
         "from this plane.%^RESET%^");
      return 1;
   }
   if(ALIGN->is_neutral(ETO)){
      tell_room(EETO,"%^BOLD%^The full plate flies apart into a "+
         "million s%^RESET%^il%^BOLD%^v%^RESET%^e%^BOLD%^r spinning "+
         "shards, and is reassembled around "+ETOQCN+"!%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^The full plate flies apart into a "+
         "million s%^RESET%^il%^BOLD%^v%^RESET%^e%^BOLD%^r spinning "+
         "shards, and is reassembled around you!%^RESET%^");
      set_short("%^RESET%^Ph%^BOLD%^a%^RESET%^nt%^BOLD%^a"+
         "%^RESET%^sm%^BOLD%^i%^RESET%^c F%^BOLD%^u%^RESET%^ll Pl"+
         "%^BOLD%^a%^RESET%^t%^BOLD%^e%^RESET%^");
      set_obvious_short("%^RESET%^A suit of r%^BOLD%^e%^RESET%^fl%^BOLD%^e"+
         "%^RESET%^ct%^BOLD%^i%^RESET%^v%^BOLD%^e %^RESET%^full plate");
      set_long("This armor is constructed entirely of thousands of "+
         "half-inch squares, seemingly bound together by no discernable "+
         "method. The squares are made of an unknown material that "+
         "appears to be an amalgam of metal and glazed ceramic. The %^BOLD%^"+
         "s%^RESET%^il%^BOLD%^v%^RESET%^e%^BOLD%^r %^RESET%^squares are "+
         "highly reflective, creating thousands of tiny mirrors over "+
         "the surface the armor. Although it readily reflects the "+
         "environment around it, this plate certainly does not hail "+
         "from this plane.%^RESET%^");
      return 1;
   }
   if(ALIGN->is_evil(ETO)){
      tell_room(EETO,"%^BOLD%^The full plate flies apart into a "+
         "million %^BOLD%^%^BLACK%^eb%^RESET%^o%^BOLD%^%^BLACK%^n "+
         "%^WHITE%^spinning shards, and is reassembled around "+
         ""+ETOQCN+"!%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^The full plate flies apart into a "+
         "million %^BOLD%^%^BLACK%^eb%^RESET%^o%^BOLD%^%^BLACK%^n "+
         "%^WHITE%^spinning shards, and is reassembled around "+
         "you!%^RESET%^");
      set_short("%^BOLD%^%^BLACK%^Ph%^RESET%^a%^BOLD%^%^BLACK%^nt"+
         "%^RESET%^a%^BOLD%^%^BLACK%^sm%^RESET%^i%^BOLD%^%^BLACK%^c "+
         "F%^RESET%^u%^BOLD%^%^BLACK%^ll Pl%^RESET%^a%^BOLD%^%^BLACK%^"+
         "t%^RESET%^e");
      set_obvious_short("%^BOLD%^%^BLACK%^A suit of r%^RESET%^e%^BOLD%^"+
         "%^BLACK%^fl%^RESET%^e%^BOLD%^%^BLACK%^ct%^RESET%^i%^BOLD%^"+
         "%^BLACK%^v%^RESET%^e %^BOLD%^%^BLACK%^full plate%^RESET%^");
      set_long("%^BOLD%^%^BLACK%^This armor is constructed entirely of "+
         "thousands of half-inch squares, seemingly bound together by "+
         "no discernable method. The squares are made of an unknown "+
         "material that appears to be an amalgam of metal and glazed "+
         "ceramic. The eb%^RESET%^o%^BOLD%^%^BLACK%^n squares are highly "+
         "reflective, creating thousands of tiny mirrors over the "+
         "surface the armor. Although it readily reflects the "+
         "environment around it, this plate certainly does not hail "+
         "from this plane.%^RESET%^");
      return 1;
   }
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^The full plate flies apart from "+ETOQCN+"'s "+
      "body into a million spinning shards!%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^The full plate flies apart from your body "+
      "into a million spinning shards!%^RESET%^");
   return 1;
}

void init(){
   ::init();
   if(stringp(owner)) return;
   if(interactive(TP) && TP == ETO){
      owner = TPQN;
      set_size(TP->query_size());
   }
}