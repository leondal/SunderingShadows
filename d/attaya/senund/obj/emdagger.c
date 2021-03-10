//Changed wield level to match +/5, also fixed the bonus removal on the special unwield - Octothorpe 6/8/09
#include <std.h>
#include "../areadefs.h"
inherit "/d/common/obj/weapon/dagger";
string OWNER;
void init()
{
    ::init();
    if(interactive(ETO) && ETO==environment(TO) && !OWNER) OWNER = ETOQN;
}

void create() {
    ::create();
    set_name("emerald dagger");
    set_id( ({"dagger","emerald dagger"}) );
    set_short("%^BOLD%^%^GREEN%^E%^RESET%^%^GREEN%^m%^BOLD%^"+
              "%^WHITE%^e%^RESET%^%^GREEN%^r%^WHITE%^%^BOLD%^a"+
              "%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^d "+
              "%^BLACK%^%^BOLD%^Dagger%^RESET%^");
    set_obvious_short("a dagger");
    set_long(
@BRUENOR
    %^GREEN%^This is a very plain looking dagger except for the ornate
%^BOLD%^emerald%^RESET%^%^GREEN%^ that makes up the pommel for the dagger. Upon closer inspection
you also notice that the blade seems to have a slight greenish
tint. Overall it seems to be a fine piece of craftsmanship%^RESET%^.
BRUENOR
    );
    set_lore(
@BRUENOR
This dagger is one item out of a pair of brother weapons, the other
being a sword made of ruby. These sentinent weapons were created many
centuries ago by the gods themselves. They eventually found their way
into the hands of Kinnesaruda. Intruder himself is rumored to have used
them for a short while. At some point not too long ago the warrior
assassin Gambrill acquired these weapons while on a job for the city of
Seneca. By itself the Emerald Dagger is a fearsome weapon, but only
when paired with the Ruby Longsword is its true power revealed.
BRUENOR
    );
    set_weight(10);
    set("value",250);
    set_property("enchantment",4);
    set_wield((:TO, "extra_wield":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO, "extra_hit":));
}
int extra_hit(object targ)
{
    if(!objectp(targ)) return 1;
        if(!random(2))
        {
        tell_object(ETO,
          "%^GREEN%^The emerald dagger %^BOLD%^glows%^RESET%^%^GREEN%^ "+
          "as you stab your opponent.");
        tell_room(EETO,
          "%^GREEN%^The emerald dagger wielded by "
          +ETOQCN+" seems to %^BOLD%^glow%^RESET%^ "+
          "%^GREEN%^as it stabs into "
          +targ->QCN+"!%^RESET%^", ({ETO,targ}));
        tell_object(targ,
          "%^GREEN%^The emerald dagger wielded by "+ETOQCN+
          " seems to %^BOLD%^glow%^RESET%^%^GREEN%^ as it stabs into you"+
          "!%^RESET%^");
        }
    return random(10)+1;
}
int extra_wield()
{
    object ob;

    if((int)ETO->query_level() < 20) {
        tell_object(ETO,"%^BOLD%^%^RED%^The emerald dagger tells you: %^RESET%^"+
        "Your weakness disgusts me..");
        return 0;
    }
     if(interactive(ETO) && (string)ETO->query_name() != OWNER){
        tell_object(ETO,"%^BOLD%^%^RED%^The emerald dagger tells you: %^RESET%^"+
                                "You are unknown to me. Leave me be.");
        return 0;
    }
      tell_object(ETO, "%^BOLD%^%^RED%^The emerald dagger tells you: %^RESET%^"+
                 "Greetings "+capitalize(ETO->query_name())+"! You shall do well in helping me.");
      tell_object(ETO,"%^GREEN%^The emerald dagger shines "+
                  "%^BOLD%^brightly.%^RESET%^");

    tell_room(EETO,
      "%^GREEN%^"+ETOQCN+" eyes glow an eerie %^BOLD%^%^RED%^red"+
      "%^RESET%^%^GREEN%^ as "+ETO->query_possessive()+" possession "+
      "%^BOLD%^%^GREEN%^sparkles%^RESET%^%^GREEN%^ momentarily."+
      "%^RESET%^",ETO);
    ETO->set_property("evil item",1);

  if((ob = present("ruby longsword",ETO)) && living(ETO) && ob != TO)
  {
     if(ob->query_wielded())
     {
        tell_room(EETO,"%^GREEN%^The dagger carried by "+
           ETOQCN+" glows slightly.%^RESET%^",ETO);
        tell_object(ETO,"%^GREEN%^The emerald dagger glows slightly.%^RESET%^");
        tell_room(EETO,"%^RED%^The longsword carried by "+
            ETOQCN+" glows slightly.%^RESET%^",ETO);
        tell_object(ETO,"%^RED%^The ruby longsword glows slightly.%^RESET%^");
            set_item_bonus("attack bonus",2);
            set_item_bonus("damage bonus",2);
            set_item_bonus("armor bonus",2);
     }
     else {
            set_item_bonus("attack bonus",0);
            set_item_bonus("damage bonus",0);
            set_item_bonus("armor bonus",0);
     }
  }
  else {
      set_item_bonus("attack bonus",0);
      set_item_bonus("damage bonus",0);
      set_item_bonus("armor bonus",0);
  }

    return 1;
}

int removeme()
{
    object ob;

    tell_object(ETO,"%^BOLD%^%^RED%^The emerald dagger tells you: %^RESET%^"
                +ETOQCN+"... Never thought you were up to it anyway%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+
    "'s eyes flash and you hear a faint mumbling as "+ETOQCN+" lets go of the "+
    "dagger.",ETO);
   ETO->set_property("evil item",-1);

  if((ob = present("ruby longsword",ETO)) && living(ETO) && ob != TO)
   {
     if(ob->query_wielded())
     {
        tell_room(EETO,"%^GREEN%^The dagger carried by "+
           ETOQCN+" ceases its glowing.%^RESET%^",ETO);
        tell_object(ETO,"%^GREEN%^The emerald dagger ceases its glowing.%^RESET%^");
        tell_room(EETO,"%^RED%^The longsword carried by "+
            ETOQCN+" ceases its glowing.%^RESET%^",ETO);
        tell_object(ETO,"%^RED%^The ruby longsword ceases its glowing.%^RESET%^");
     }

   }
   return 1;
}
