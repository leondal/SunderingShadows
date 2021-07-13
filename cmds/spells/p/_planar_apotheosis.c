#include <std.h>
#include <priest.h>

inherit SPELL;

int counter, myresist, resistflag, extra, flag, duration, mylevel;
string mytype;

void emote_em(string str);

void create() {
    ::create();
    set_spell_name("planar apotheosis");
    set_spell_level(([ "psywarrior" : 4 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS planar apotheosis on CELESTIAL|FIENDISH");
    set_description("When manifesting this power, the psionic character "
      "chooses to embrace the powers of either the celestial or the fiendish. "
      "The planar energy chosen grants special resistances and imbues the "
      "manifester with a protective force. Once each round, the energy "
      "automatically lashes out at one of his foes, striking him with fiendish "
      "or celestial energy. The duration of this power grows with the psionic character.");
    set_verbal_comp();
    set_bonus_type("resistance");
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell() {
    if(!arg){
       tell_object(caster,"Please specify the type of energy you "
          "would like to embrace - celestial or fiendish.");
       return 0;
    }
    if (caster->query_property("apotheosis")) {
      tell_object(caster,"You are already under the effects of this power!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
   mytype = arg;
   mylevel = clevel;
   duration = (ROUND_LENGTH * 10) * mylevel;
   myresist = (mylevel/2) + 5; //lower than other resistance spells because it is lower level and grants specific resistances as well. Adjust if needed.
   if(mytype == "fiendish"){
      tell_object(caster,"%^BOLD%^%^BLACK%^You reach into the depths of "
         "the %^RESET%^Abyss%^BOLD%^%^BLACK%^ and bring forth otherwordly energies, "
         "feeling them settle into your very skin.%^RESET%^");
      tell_room(place,"%^BOLD%^%^BLACK%^Darkness suddenly surrounds "+caster->QCN+" "
         "%^BOLD%^%^BLACK%^and "+caster->QP+" eyes %^RESET%^g%^BOLD%^%^BLACK%^l"
         "%^RESET%^i%^BOLD%^%^BLACK%^t%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^r "
         "%^BOLD%^%^BLACK%^briefly.%^RESET%^",caster);
      caster->set_resistance("cold",10);
      caster->set_resistance("fire",10);
      caster->set_resistance("electricity",10);
      caster->set_property("spell damage resistance",myresist);
   }    
   else if(mytype == "celestial"){
      tell_object(caster,"%^BOLD%^%^WHITE%^You reach into the shimmering "
         "%^RESET%^%^CYAN%^Astral Plane%^BOLD%^%^WHITE%^ and bring forth otherwordly energies, "
         "feeling them settle into your very skin.%^RESET%^");
      tell_room(place,"%^BOLD%^%^WHITE%^An %^RESET%^%^CYAN%^ethereal glow"
         "%^BOLD%^%^WHITE%^ suddenly surrounds "+caster->QCN+" "
         "%^BOLD%^%^WHITE%^and "+caster->QP+" eyes %^RESET%^g%^BOLD%^l"
         "%^RESET%^i%^BOLD%^t%^RESET%^t%^BOLD%^e%^RESET%^r "
         "%^BOLD%^briefly.%^RESET%^",caster);
      caster->set_resistance("cold",10);
      caster->set_resistance("acid",10);
      caster->set_resistance("electricity",10);
      caster->set_property("spell damage resistance",myresist);
   }else{
      tell_object(caster,"That is not a valid type! Please choose celestial or fiendish.");
      return;
   }
   caster->set_property("spelled", ({TO}) );
   caster->set_property("apotheosis",1);
   addSpellToCaster();
   spell_successful();
   environment(caster)->addObjectToCombatCycle(TO,1);
   call_out("emote_em",15*ROUND_LENGTH,mytype);
   spell_duration = duration;
   set_end_time();
   call_out("dest_effect",spell_duration);
}

void execute_attack(){
   object ppl;
   string baddie;
    if (!flag) {
        ::execute_attack();
        flag = 1;
        return;
    }
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
   ppl = caster->query_current_attacker();
   if (ppl && objectp(ppl)){
      baddie = ppl->QCN;
      extra = ((mylevel*2)/3);
      if(!objectp(ppl)) return;
      if(mytype == "fiendish"){
         tell_room(environment(caster),"%^BOLD%^%^BLACK%^The %^RESET%^shadows "
            "%^BOLD%^%^BLACK%^surrounding "+caster->QCN+" %^BOLD%^"
            "%^BLACK%^suddenly surge forward, "+
            "lashing out at "+baddie+"%^BOLD%^%^BLACK%^.%^RESET%^",({caster,ppl}));
         tell_object(caster,"%^BOLD%^%^BLACK%^The %^RESET%^shadows %^BOLD%^%^BLACK%^surrounding you "
            "coalesce, lashing out at "+baddie+"%^BOLD%^%^BLACK%^!%^RESET%^");
         tell_object(ppl,"%^BOLD%^%^BLACK%^The %^RESET%^shadows %^BOLD%^%^BLACK%^surrounding "+
            ""+caster->QCN+" %^BOLD%^%^BLACK%^coalesce and lash out at you!%^RESET%^");
      }else{
         tell_room(environment(caster),"%^BOLD%^%^WHITE%^A flash of blinding %^CYAN%^"
            "light%^WHITE%^ beams from "+caster->QCN+"%^BOLD%^%^WHITE%^'s eyes, striking "
            ""+baddie+"%^BOLD%^%^WHITE%^!%^RESET%^",({caster,ppl}));
         tell_object(caster,"%^BOLD%^%^WHITE%^Heat builds within you before a beam "
            "of blinding %^CYAN%^light %^WHITE%^lashes out, striking "+baddie+"%^BOLD%^%^WHITE%^!%^RESET%^");
         tell_object(ppl,"%^BOLD%^%^WHITE%^A flash of blinding %^CYAN%^"
            "light%^WHITE%^ beams from "+caster->QCN+"%^BOLD%^%^WHITE%^'s eyes, striking "
            "you!%^RESET%^");
      }
      damage_targ(ppl,ppl->return_target_limb(),extra,"mental");
      counter++;
      if (counter > mylevel) {
          dest_effect();
          return;
      }
    }
    environment(caster)->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
   if(objectp(caster)){
      tell_object(caster,"%^CYAN%^You feel the planar energy drain from you.");
      tell_room(environment(caster),"%^CYAN%^The field of energy "+
         "surrounding "+caster->QCN+" fades away.",caster);
      caster->set_resistance("cold",-10);
      caster->set_resistance("electricity",-10);
      if(mytype == "fiendish"){
         caster->set_resistance("fire",-10);
      }else{
         caster->set_resistance("acid",-10);
      }

      caster->set_property("spell damage resistance",-1*myresist);
      caster->remove_property("apotheosis");
   }
   ::dest_effect();
   if(objectp(TO)) TO->remove();

}

void emote_em(string str){
   mytype = str;
   if(sizeof(caster->query_attackers()) > 0){
      call_out("emote_em",5*ROUND_LENGTH,mytype);
      return;
   }
   if(mytype == "fiendish"){
      switch(random(5)){
         case 0: tell_room(environment(caster),"%^RESET%^%^BLUE%^"+caster->QCN+""
                    "%^RESET%^%^BLUE%^'s exposed skin takes on a faint blue cast before "
                    "it fades away.%^RESET%^",caster);
                 tell_object(caster,"%^RESET%^%^BLUE%^You feel a surge of dark energy "
                    "test your mental resilience before it settles once more.%^RESET%^");
                 break;
         case 1: tell_room(environment(caster),"%^BOLD%^%^BLACK%^A pair of %^RESET%^shadowy "
                    "wings %^BOLD%^%^BLACK%^sprout from "+caster->QCN+"%^BOLD%^%^BLACK%^'s "
                    "back and then shrink away again.%^RESET%^",caster);
                 tell_object(caster,"%^BOLD%^%^BLACK%^Heat flushes your skin and you feel an "
                    "itch between your shoulder blades that soon fades away.%^RESET%^");
                 break;
         case 2: tell_room(environment(caster),"%^BOLD%^%^BLACK%^"+caster->QCN+"%^BOLD%^"
                    "%^BLACK%^'s eyes suddenly %^RESET%^%^RED%^glo%^BOLD%^w%^RESET%^%^RED%^ "
                    "red%^BOLD%^%^BLACK%^ before returning to their normal hue.%^RESET%^",caster);
                 tell_object(caster,"%^BOLD%^%^BLACK%^You feel the %^RESET%^%^RED%^"
                    "fi%^BOLD%^r%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^within blaze before "
                    "dampening just as quickly.%^RESET%^");
                 break;
         case 3: tell_room(environment(caster),"%^RESET%^%^RED%^The scent of %^BOLD%^br"
                    "%^RESET%^%^RED%^i%^BOLD%^ms%^BLACK%^t%^RED%^o%^RESET%^n%^BOLD%^%^RED%^e "
                    "%^RESET%^%^RED%^fills the air around "+caster->QCN+"%^RESET%^%^RED%^.%^RESET%^",caster);
                 tell_object(caster,"%^RESET%^%^RED%^The scent of %^BOLD%^br%^RESET%^%^RED%^"
                    "i%^BOLD%^ms%^BLACK%^t%^RED%^o%^RESET%^n%^BOLD%^%^RED%^e %^RESET%^%^RED%^rises "
                    "all around you.%^RESET%^");
                 break;
         default: tell_room(environment(caster),"%^BOLD%^%^BLACK%^The %^RESET%^shadows "
                    "%^BOLD%^%^BLACK%^around "+caster->QCN+" %^BOLD%^%^BLACK%^shift, "
                    "distorting "+caster->QP+" face into a terrifying mask. With a hint "
                    "of a light %^RESET%^%^CYAN%^breeze%^BOLD%^%^BLACK%^, the illusion "
                    "dissipates.%^RESET%^",caster);
                 tell_object(caster,"%^BOLD%^%^BLACK%^You fight back a smile as you feel "
                    "a fiendish warmth deep within your soul.%^RESET%^");
                 break;
      }
   }
   if(mytype == "celestial"){
      switch(random(5)){
         case 0: tell_room(environment(caster),"%^RESET%^%^CYAN%^As "+caster->QCN+""
                    "%^RESET%^%^CYAN%^ turns "+caster->QP+" head, "+caster->QCN+" "
                    "sparkle with an %^BOLD%^o%^WHITE%^p%^CYAN%^al%^MAGENTA%^e%^CYAN%^"
                    "sc%^WHITE%^e%^CYAN%^nt %^RESET%^%^CYAN%^gleam.%^RESET%^",caster);
                 tell_object(caster,"%^RESET%^%^CYAN%^You feel a surge of %^BOLD%^joy"
                    "%^RESET%^%^CYAN%^ as warmth spreads across your skin.%^RESET%^");
                 break;
         case 1: tell_room(environment(caster),"%^YELLOW%^A stray beam of light appears, "
                    "casting its glow on "+caster->QCN+"%^YELLOW%^'s hair and giving it "
                    "an unearthly %^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r "
                    "%^BOLD%^s%^RESET%^h%^BOLD%^e%^RESET%^e%^BOLD%^n%^YELLOW%^.%^RESET%^",caster);
                 tell_object(caster,"%^YELLOW%^You are briefly bathed in a warm, radiant glow.%^RESET%^");
                 break;
         case 2: tell_room(environment(caster),"%^RESET%^%^ORANGE%^As you look on, a cascade "
                    "of %^CYAN%^ir%^RESET%^i%^CYAN%^des%^BOLD%^c%^RESET%^%^CYAN%^ent fe%^BOLD%^"
                    "%^WHITE%^a%^RESET%^%^CYAN%^the%^BOLD%^r%^RESET%^%^CYAN%^s %^RESET%^%^ORANGE%^"
                    "sprouts from %^"+caster->QCN+"%^RESET%^%^ORANGE%^'s shoulders before fading away.%^RESET%^",caster);
                 tell_object(caster,"%^RESET%^%^CYAN%^Something tickles your ear just before you see a single "
                    "%^CYAN%^ir%^RESET%^i%^CYAN%^des%^BOLD%^c%^RESET%^%^CYAN%^ent fe%^BOLD%^"
                    "%^WHITE%^a%^RESET%^%^CYAN%^th%^BOLD%^e%^RESET%^%^CYAN%^r%^RESET%^%^ORANGE%^ float before your eyes.%^RESET%^");
                 break;
         case 3: tell_room(environment(caster),"%^BOLD%^%^WHITE%^A smattering of "
                    "%^RESET%^%^CYAN%^ir%^BOLD%^i%^RESET%^%^CYAN%^des%^BOLD%^%^MAGENTA%^c"
                    "%^RESET%^%^CYAN%^ent s%^BOLD%^%^WHITE%^c%^RESET%^%^CYAN%^a%^BOLD%^l"
                    "%^RESET%^%^CYAN%^es %^BOLD%^%^WHITE%^briefly covers "+caster->QCN+""
                    "%^BOLD%^%^WHITE%^'s exposed skin.%^RESET%^",caster);
                 tell_object(caster,"%^BOLD%^%^WHITE%^You feel a brush against your "
                    "skin like angelic fingertips.%^RESET%^");
                 break;
         default: tell_room(environment(caster),"%^RESET%^%^ORANGE%^"+caster->QCN+""
                    "%^RESET%^%^ORANGE%^'s skin takes on a %^YELLOW%^golden glow%^RESET%^"
                    "%^ORANGE%^ before returning to its usual hue.%^RESET%^",caster);
                 tell_object(caster,"%^RESET%^%^ORANGE%^You feel warmth against your skin, "
                    "like the gentle kiss of a warm fire in the hearth.%^RESET%^");
                 break;
      }
   }
   call_out("emote_em",15*ROUND_LENGTH,mytype);
   return;
}
