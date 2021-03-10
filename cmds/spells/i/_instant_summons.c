// Drawmij's Instant Summons. Coded by Lujke July 2005
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string tmp,YOU,HIM, word;
object place, caster;

void damage();

void create() {
    ::create();
    set_spell_name("instant summons");
    set_spell_level(([ "mage" : 7 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS instant summons on ITEM, with password PASSWORD");
    set_description("To cast this spell, the mage must use a gem of at least 100 gold value. This will need to be an actual gem found somewhere in the realms; 'spell component' gems won't do (Wizbert says that it's something to do with the special way 'component' gems are cut. Sounds plausible, but then again everyone knows Wizbert talks rubbish a lot of the time).

At the time of casting, the mage identifies an item from her inventory that she wants to be able to summon at a later date. She also names a specific password to activate the spell. Once the spell is cast, the item can be stored wherever the mage chooses and she carries the gem with her. When she wishes to retrieve the item, she crushes the gem while saying the password: <crush gem while saying PASSWORD>

The gem will then crumble to dust and the item should appear in its place. This can go wrong. If the item no longer exists it can't be summoned. If the item is in someone else's posession, it won't be summoned, but the mage will get a brief flash of a vision of where the item is, and who has it.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
}

string query_cast_string() {
  object env;
  if (!objectp(caster)){
    notify_fail("ERROR - spell caster is invalid! Please tell a wiz");
    return ("");
  }
  return caster->QCN+" ";
}

void spell_effect(int prof) {
 string item_name, password, caster_speech, caster_speech_describe;
  object gem, item, newgem;
 int hasgem = 0, gemcost = 0,i,j;
  caster = CASTER;
  place = PLACE;
  if (!objectp(caster)||!objectp(place)){return;}
  YOU=caster->QCN;
  if (sizeof(all_inventory(caster))<1){
    tell_object(caster, "You don't have a gem!");
    dest_effect();
  }
  for (i=0;i<sizeof(all_inventory(caster));i++){
    gem = all_inventory(caster)[i];
    if (objectp(gem)){
      if (gem->id("gem")){
        hasgem = 1;
        if (gem->query_value()>=100){
          gemcost = gem->query_value();
          break;
        }
      }
    }

  }
  if (hasgem==0){
    tell_object(caster, "You don't have a gem!");
    dest_effect();
  }
  if (gemcost <500){
    tell_object(caster, "You don't have a gem that is worth enough!");
    dest_effect();
  }
  sscanf(arg, "%s, with password %s",item_name, password);
  if (item_name ==0||password==0){
    tell_object(caster, "Try: %^YELLOW%^cast instant"
                       +" summons on <item>, with password <password>");
    return 1;
  }
  item = present(item_name,caster);
  if (!objectp(item)){
    tell_object(caster, "You don't have a " + item_name);
    dest_effect();  }
  spell_successful();
  if ( !interactive(caster) && !caster->query_invis() )
    YOU=caster->QCN;
  newgem = new ("/d/magic/obj/summoning_gem.c");


  newgem->set_item(item_name,password,caster);
  newgem->set_long(gem->query_long()+ "\nIt has a very faint mark on it,"
                                     +" like a miniscule inscription");
  newgem->set_short(gem->query_short());
  newgem->set_read("The inscription is far too small to read");
  newgem->set_value(gem->query_value());
  newgem->set_weight(gem->query_weight());
  if(objectp(gem)) gem->remove();
  newgem->move(caster);
  caster->force_me("emote makes a few arcane passes with his hands over"
                  +" the gem");
  caster_speech_describe = (string)caster->query("describe string");
  caster_speech = (string)caster->query("speech string");
 caster->force_me("speech %^GREEN%^intone %^CYAN%^rhythmically%^RESET%^");
  caster->force_me("say In summoning spirits, in summoning power");
  caster->force_me("say Draw this to me when I name the hour");
  caster->force_me("say and let the name of the summoning be " + password
                  +"!");
   if (caster_speech_describe != 0)
   {
      caster_speech += " " + caster_speech_describe;
   }

  caster->force_me("speech" + " "+ caster_speech);
  dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
