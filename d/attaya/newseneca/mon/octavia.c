//octavia.c - comp vendor for the mage tower in new Seneca
//tiefling, at war with Godfrey, the aasimar spell vendor
//familiar stuff adapted from /d/newbie/mon/zabeth
//~Circe~ 1/7/08

#include <std.h>
#include "../seneca.h"

inherit "/std/comp_vend.c";

void buff_up(object myself, object target, int stage);
void summon_familiar(object myself, object familiar);

void create(){
object ob;
   ::create();
   set_name("octavia");
   set_id(({"octavia","clerk","shop keeper","shopkeeper","vendor","Octavia","octavia maleficant","Octavia Maleficant"}));
   set_short("Octavia Maleficant, Enchantress of Impish Charms");
   set("aggressive", 0);
   set_long("Clad in a form-fitting gown of %^BOLD%^%^BLACK%^ebony "+
      "%^RESET%^%^CYAN%^highlighted with %^BOLD%^%^GREEN%^glowing "+
      "embroidery%^RESET%^%^CYAN%^, this graceful woman commands "+
      "a power all her own.  Her %^BOLD%^%^BLACK%^hair %^RESET%^"+
      "%^CYAN%^is pulled into an elaborate %^BOLD%^%^BLACK%^"+
      "topknot %^RESET%^%^CYAN%^bounded by a %^BOLD%^%^GREEN%^"+
      "runed band%^RESET%^%^CYAN%^ with the ponytail left "+
      "trailing down her back.  The bodice of her gown seems "+
      "to defy gravity, possessing no straps and standing above "+
      "her full breasts in a mockery of %^BOLD%^%^WHITE%^wings "+
      "%^RESET%^%^CYAN%^made all the more sinister for their "+
      "%^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^and %^BOLD%^"+
      "%^GREEN%^green %^BLACK%^c%^GREEN%^o%^BLACK%^l%^GREEN%^o"+
      "%^BLACK%^r%^GREEN%^i%^BLACK%^n%^GREEN%^g%^RESET%^"+
      "%^CYAN%^.  Her slender shoulders are tattooed with "+
      "%^RED%^runes %^CYAN%^that seem to pulse with energy, "+
      "echoing her stormy %^BOLD%^%^GREEN%^em%^WHITE%^e%^GREEN%^"+
      "ra%^BLACK%^l%^GREEN%^d eyes%^RESET%^%^CYAN%^ with cat-like "+
      "%^BOLD%^%^BLACK%^pupils%^RESET%^%^CYAN%^.  Hinting "+
      "at an other-worldly heritage, her pointed %^BOLD%^%^WHITE%^"+
      "fangs %^RESET%^%^CYAN%^can be seen over her plump lips, "+
      "while the tell-tale sign is the click of the hooves "+
      "hidden beneath her gown when she moves.  She is "+
      "never removed from the loyal %^BOLD%^%^BLACK%^imp "+
      "servant %^RESET%^%^CYAN%^she has taken for her own.%^RESET%^"+
      "\nTo get a list of shop commands, type <help shop>."
   );
   set_gender("female");
   set_alignment(6);
   set_race("tiefling");
   set_class("mage");
   set_hd(40,8);
   set_level(40);
   set_guild_level("mage",40);
   set_body_type("human");
   set_property("no bump", 1);
   set_emotes(3,({"%^MAGENTA%^Octavia cackles%^RESET%^: This "+
      "will show that oaf, Godfrey!","%^MAGENTA%^Octavia yawns"+
      "%^RESET%^: That Godfrey...he really is such a bore!","Octavia "+
      "mutters to herself "+
      "as she mixes a concoction of wormwood, granite dust, and "+
      "vampire bat wing.","Octavia licks her lips slowly.","Octavia's "+
      "tail slithers out of the bottom of her gown."}), 0);
   set_emotes(10, ({"%^BOLD%^%^BLACK%^Octavia's eyes %^GREEN%^flash "+
      "%^BLACK%^as she lashes out with her tail!%^RESET%^",
      "%^MAGENTA%^Octavia snarls%^RESET%^: That snivelling rat Godfrey "+
      "put you up to this, didn't he?!","Octavia screeches and slices "+
      "with her claws!"}), 1);
   set_components(100);
   set_spell_chance(100);
   set_spells(({"fireball","lightning bolt","acid arrow",
        "powerword stun", "incendiary cloud", "magic missile"}));
   set_property("strength","spells");
   ob = new(MON"imp.c");
   ob->set_property("my_master",TO);
   TO->set_property("my_familiar",ob);
   call_out("summon_familiar",1,TO,ob);
}

void summon_familiar(object myself, object familiar) {
  if ( (!objectp(familiar)) || (!objectp(TO)) || (!objectp(ETO)) ) return;
  familiar->move(environment(myself));
  tell_room(ETO,capitalize(familiar->query_name()) + " bounds into the room cackling.");
  call_out("buff_up",1,myself,familiar,1);
  call_out("buff_up",6,myself,myself,2);
  return;
}

void buff_up(object myself, object target, int stage) {
   if ( (!objectp(target)) || (!objectp(myself)) || (!objectp(environment(myself))) ) return;
   if (!present(target,environment(myself))) return;
   switch (stage++){
      case 1:
         new("/cmds/spells/a/_armor.c")->use_spell(myself,(string)target->query_name(),40,120,"mage");
         call_out("buff_up",0,myself,target,stage);
         break;
      case 2:
         new("/cmds/spells/s/_stoneskin.c")->use_spell(myself,(string)target->query_name(),40,120,"mage"); 
         break;
      default:
         break;
   }
   return;
}