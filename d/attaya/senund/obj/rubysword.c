#include <std.h>
#include "../areadefs.h"
inherit "/d/common/obj/weapon/longsword";
string OWNER;
void init()
{
    ::init();
    if(interactive(ETO) && ETO==environment(TO) && !OWNER) OWNER = ETOQN;
}

void create()
{
    ::create();
    set_name("ruby longsword");
    set_id( ({"sword","longsword","ruby sword","ruby","ruby longsword"}) );
    set_short("%^RED%^Ruby Longsword%^RESET%^");
    set_obvious_short("a longsword");
    set_long(
@BRUENOR
This is a grizzly looking longsword. The longsword is detailed with many
%^BOLD%^%^RED%^bloody%^RESET%^ depictions of dying %^BOLD%^%^GREEN%^elves%^RESET%^. Its blade glows a sickly
%^RED%^red%^RESET%^ and contains two jagged %^BLUE%^%^BOLD%^serrated%^RESET%^ edges along with a long %^RED%^blood%^RESET%^ vein.
The hilt of the blade is ornamented with the finest %^BOLD%^%^RED%^rubies%^RESET%^. Overall
this longsword gives you a feeling of dread.
BRUENOR
    );
    set_lore(
@BRUENOR
This longsword is one item out of a pair of brother weapons, the other
being a dagger made of emerald. These sentinent weapons were created many
centuries ago by the gods themselves. They eventually found their way
into the hands of Kinnesaruda. Intruder himself is rumored to have used
them for a short while. At some point not too long ago the warrior
assassin Gambrill acquired these weapons while on a job for the city of
Seneca. By itself the Ruby Longsword is a fearsome weapon, but only
when paired with the Emerald Dagger is its true power revealed.
BRUENOR
    );
    set_weight(10);
    set("value",250);
    set_wield((:TO, "extra_wield":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO, "extra_hit":));
}
int extra_hit(object targ)
{
    string plname;
    int dam;
    int count;
    dam = random(10);
    plname = ETO->query_name();
    if(!objectp(targ)) return 1;
        if(!random(4))
        {
        tell_object(ETO,
          "%^BOLD%^%^MAGENTA%^The ruby longsword seems to cackle as you swing.");
        tell_room(EETO,
          "%^BOLD%^%^MAGENTA%^The ruby longsword wielded by "
          +ETOQCN+" seems to cackle as it slashes "
          +targ->QCN+"!%^RESET%^", ({ETO,targ}));
        tell_object(targ,
          "%^BOLD%^%^MAGENTA%^The ruby longsword wielded by "+ETOQCN+
          " lets out an deafening cackle as it shears into you!%^RESET%^");
        set_property("magic",1);
        targ->do_damage("torso",random(10));
        set_property("magic",-1);
        }
        if(!random(4))
        {
        if(dam < 9)
        {
            tell_object(ETO,
                    "%^BLUE%^The longswords jagged edge %^RED%^cuts%^BLUE%^ into "+
                    "your opponent!%^RESET%^");
            tell_room(EETO,
                    "%^BLUE%^The longswords jagged edge wielded by "
                    +ETOQCN+
                    " %^RED%^cuts%^BLUE%^ into "+targ->QCN+
                    "!%^RESET%^",({ETO,targ}));
            tell_object(targ,
                    "%^BLUE%^The longswords jagged edge %^RED%^cuts%^BLUE%^ "+
                    "into you!%^RESET%^");
        ETO->set_property("magic",1);
        targ->do_damage("torso",roll_dice(3,6));
        ETO->set_property("magic",-1);
        }
        else
        {
            tell_object(ETO,
                "%^BOLD%^%^GREEN%^Your opponent screeches in severe pain!%^RESET%^");
            tell_room(EETO,
                "%^BOLD%^%^GREEN%^"+targ->QCN+
                " is hit by intense pains!%^RESET%^",({ETO,targ}));
            tell_object(targ,
                "%^BOLD%^%^GREEN%^Intense pain shoots through your skull,"+
                " distorting your senses!%^RESET%^");
        ETO->set_property("magic",1);
        targ->do_damage("torso",roll_dice(5,5));
        ETO->set_property("magic",-1);
        }
    }
        return 1;
}
int extra_wield()
{
    object ob;
    int max;

    if((int)ETO->query_level() < 25) {
        tell_object(ETO,"%^BOLD%^%^RED%^The ruby longsword tells you: %^RESET%^"+
        "I refuse to be wielded by one as weak as you!");
        return 0;
    }

     if(interactive(ETO) && (string)ETO->query_name() != OWNER){
        tell_object(ETO,"%^BOLD%^%^RED%^The ruby longsword tells you: %^RESET%^"+
                                "I do not know you. Leave me be!");
        return 0;
    }
    if( (ETO->is_class("fighter")) ||
    ((string)ETO->query_name()=="bruenor") )
     {
        tell_object(ETO,
        "%^BOLD%^%^RED%^The ruby longsword tells you: %^RESET%^"+
        "Finally a true warrior!");
        tell_object(ETO, "%^BOLD%^%^GREEN%^%^The longsword "+
        "flashes every color of the spectrum as you wield it!%^RESET%^");
    }
      tell_object(ETO, "%^BOLD%^%^RED%^The ruby longsword tells you: %^RESET%^"+
                 "Gooday "+capitalize(ETO->query_name())+"! Time to slay those who oppose us!");
      tell_object(ETO,"%^BOLD%^%^BLUE%^The ruby longsword glows %^RED%^red%^RESET%^ "+
      "%^BOLD%^%^BLUE%^and your hands almost seem to %^RED%^burn!%^RESET%^");

    tell_room(EETO,
      "%^RED%^"+ETOQCN+" eyes glow an eery %^BOLD%^%^GREEN%^green"+
      "%^RESET%^%^RED%^ as "+ETO->query_possessive()+" possession "+
      "begins glowing red.%^RESET%^",ETO);

    max = 3;
    if (ETO->is_class("fighter")) max++;
    set_property("enchantment", max);
    while((query_property("enchantment") < 0)||(query_property("enchantment") > 4))
    {
        remove_property("enchantment");
        set_property("enchantment", max);
    }

  if((ob = present("emerald dagger",ETO)) && living(ETO) && ob != TO)
  {
     if(ob->query_wielded())
     {
        tell_room(EETO,"%^GREEN%^The dagger carried by "+
           ETOQCN+" glows slightly.%^RESET%^",ETO);
        tell_object(ETO,"%^GREEN%^The emerald dagger glows slightly.%^RESET%^");
        tell_room(EETO,"%^RED%^The longsword carried by "+
            ETOQCN+" glows slightly.%^RESET%^",ETO);
        tell_object(ETO,"%^RED%^The ruby longsword glows slightly.%^RESET%^");
     }
  }

    return 1;
}

int removeme()
{
    string name;
    object ob;
    name = ETO->query_name();
    name = capitalize(name);
    tell_object(ETO,"%^BOLD%^%^RED%^The ruby longsword tells you: %^RESET%^"
                +name+"! How dare %^WHITE%^you %^RESET%^"+
                        "unwield me!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETOQCN+
    "'s eyes flash and you hear a faint mumbling as he lets go of his "+
    "blade.",ETO);
if( (ETO->is_class("fighter")) || ((string)ETO->query_name()=="bruenor") )
     {
        tell_object(ETO,
        "%^BOLD%^%^RED%^The ruby longsword tells you: %^RESET%^"+
        "Do not let me fall into the hands of an idiot.");
    }
  if((ob = present("emerald dagger",ETO)) && living(ETO) && ob != TO)
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
   TO->remove_property("enchantment");
   return 1;
}

void save_me(string file){

        int enchantment = query_property("enchantment");
        remove_property("enchantment");
        ::save_me(file);
        while(query_property("enchantment") != enchantment) {
            remove_property("enchantment");
            set_property("enchantment",enchantment);
        }
}
