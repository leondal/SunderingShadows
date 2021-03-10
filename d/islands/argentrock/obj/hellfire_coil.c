#include <std.h>

inherit "/d/common/obj/weapon/claw.c";

// object ob2;  moved this to be a local variable only *Styx* 12/25/05

void create(){
        ::create();
        set_name("leather coil");
        set_id(({"leather coil","gauntlet","red gauntlet","spiked gauntlet","claws","weapon","spiked coil","coil","claw","hellfire coil"}));
        set_obvious_short("%^RESET%^%^RED%^A spiked red leather coil%^RESET%^");
        set_short("%^RESET%^%^RED%^H%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ll"+
                "f%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^re Coil%^RESET%^");
        set_long("%^RESET%^Twisted into a coil is a length of soft "+
                "smooth %^RED%^red%^RESET%^ leather.  The coil looks "+
                "to have been made to wrap around one's forearms.  "+
                "Attached to the smallest end of the coil is a leather"+
                " strip in the same shade of %^RED%^dark red%^RESET%^.  "+
                "The inside of the strip and coil have been finished off"+
                " with %^BOLD%^%^BLACK%^black%^RESET%^ suede, giving some"+
                " cushion anyone who might wear it.  Studded into the leather"+
                " coil and strip are over a hundred and thirty %^BOLD%^metal "+
                "spikes%^RESET%^.  Fashioned out of %^BOLD%^%^RED%^fever iron"+
                "%^RESET%^, each spike has a %^BOLD%^%^RED%^bright red%^RESET%^"+
                " hue to it.  The spikes range in size from half an inch tall to"+
                " two inches in an orderly pattern.%^RESET%^\n");
        set_lore("The new rulers of Argentrock, the fey'ri crafted "+
                "these Hellfire Coils as a sign of their mastery over magic. "+
                " Using their natural elven knowledge of magic, coupled with "+
                "secrets stolen from demonkind, the fey'ri have twisted the "+
                "the mystical arts to something much more sinister than that of "+
                "their sun elven ancestors.  The coils allow the fey'ri to summon "+
                "one of their favorite breed of canines, hellhounds, to serve "+
                "as their protector.  The coils are so common with the fey'ri "+
                "that any child showing a promise of magical power is first "+
                "instructed how to make one.  From there, it is not uncommon "+
                "for the fey'ri to further add enchantments to their coiled "+
                "spike gauntlets, making them far more deadlier.");
      set_property("lore difficulty",23);
      set_property("enchantment",4);
      set_item_bonus("bonus_spell_slots",1);
        set_item_bonus("fire resistance",2);
      set_value(3000);
      set_ac(1);
      set_wield((:TO,"wield_func":));
      set_unwield((:TO,"unwield_func":));
      set_hit((:TO,"hit_func":));
}
int wield_func(string str) {
     if((int)ETO->query_lowest_level() < 30) {
        tell_object(ETO,"%^RED%^The coil refuses you!");
        return 0;
        }
      tell_object(ETO,"%^RED%^You wrap the spiked coil around your forearm,"+
                " slipping the strip over your hand.");
                        ETO->set_property("evil item",1);
                     return 1;
}
int unwield_func(string str) {
        tell_object(ETO,"%^RED%^You unwrap the coil around your forearm, slipping"+
                " the strip off.");
                        ETO->set_property("evil item",-1);
                  return 1;
}
int hit_func(object victim)
{
    object ob2;
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(victim)) return 1;

    if(random(1000) < 220)
    {
        switch(random(50))
        {
        case 0..34:
            tell_object(ETO,"%^RED%^You slam the spikes of your coiled "+
                "gauntlet into "+victim->QCN+"'s chest, violently "+
                "tearing into "+victim->QO+".");
            tell_object(victim,"%^RED%^"+ETO->QCN+" slams the spikes of"+
                " "+ETO->QP+" gauntlet into your chest, violently tearing"+
                " into you.",);
            tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+" slams the "+
                "spikes of "+ETO->QP+" coiled gauntlet into"+
                " "+victim->QCN+"'s chest, violently tearing into"+
                " "+victim->QO+".",({ETO,victim}));
            victim->cause_typed_damage(victim,0,roll_dice(1,8)+3,"piercing");
            break;

        case 35..46:
            tell_object(ETO,"%^BOLD%^%^RED%^Time seems to slow down for you,"+
                " allowing you to hammer into "+victim->QCN+" "+
                "with a series of kidney punches, digging the spikes of "+
                "your gauntlet into "+victim->QP+" flesh.");
            tell_object(victim,"%^BOLD%^%^RED%^"+ETO->QCN+" suddenly moves"+
                " swiftly, hammering into your with a series of kidney "+
                "punches before you can even react.  With each punch metal"+
                " spikes tear into your flesh.",);
            tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" suddenly"+
                " moves swiftly, hammering into "+victim->QCN+" with a "+
                "series of kidney punches.",({ETO,victim}));
            victim->cause_typed_damage(victim,0,roll_dice(1,8)+3,"bludgeoning");
            ETO->execute_attack();
            ETO->execute_attack();
            break;

        case 47..49:
            tell_object(ETO,"%^BOLD%^%^BLACK%^The gauntlet almost seems to take"+
                " control of your hand, moving it through a series of odd "+
                "gestures.\nIn a blazing fire a %^BOLD%^%^RED%^hellhoud%^BLACK%^"+
                " appears next to you, standing in your defense.");
            tell_object(victim,"%^BOLD%^%^BLACK%^"+ETO->QCN+" starts to move"+
                " "+ETO->QP+" hand through a series of odd gestures.\n"+
                "In a blazing fire a %^BOLD%^%^RED%^hellhound%^BLACK%^ "+
                "appears next to "+ETO->QCN+", standing in "+ETO->QP+" defense.");
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" starts to move"+
                " "+ETO->QP+" hand through a series of odd gestures.\n"+
                "In a blazing fire a %^BOLD%^%^RED%^hellhound%^BLACK%^ "+
                "appears next to "+ETO->QCN+", standing in "+ETO->QP+" "+
                "defense.",({ETO,victim}));
            ob2=new("/d/islands/argentrock/mon/hellhound.c");
            ob2->move(EETO);
            ob2->force_me("protect "+ETO->query_name());
            ETO->add_follower(ob2);
            break;

        default:
            tell_object(ETO,"%^BOLD%^%^RED%^Congrats, Turbo.  You get"+
                " the special screwed up message.  Please bug report this"+
                " and what you were doing/fighting when you got this message.");
            break;

        }

    return 1;
    }
}
