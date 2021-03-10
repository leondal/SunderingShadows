
//Coded by Bane//
#include <std.h>
inherit WEAPON;

string owner;
void create(){
    ::create();
    set_id(({"sword","long sword","ragnarok","Ragnarok"}));
    set_name("%^RED%^Ragnarok");
   set_short("%^RED%^Ragnarok, destroyer of worlds%^RESET%^");
    set_long(
	"You hold before you the most destructive weapon ever created.  Born "+
	"at the worlds beginning, this swords destiny is to end what was "+
	"once born with it...the world.  Forged of an unknown element its "+
	"stronger than steel and can fell the mightest of monsters with but a "+
	"single slice of its gleaming blade.  The blade itself is so sharp it can "+
	"cut through stone like it was paper.  As you wield this devastating weapon "+
	"of death an incredible feeling of power surges through your body!"
    );
    set_weight(6);
    set_size(2);
    set_value(10000);
    set_wc(1,8);
    set_large_wc(1,12);
   set_type("slashing");
    set_hit((:TO,"quake":));
    set_wield((:TO,"extra_wield":));
   set_unwield((:TO,"removeme":));
    set_property("enchantment",4);
    set_heart_beat(1);
}
int extra_wield(){
    object tp;
    tp = this_player();
    if(!tp) return 0;
    if(tp->query_level() < 25){
	write("%^BOLD%^RED%^Ragnarok is insulted that such a pathetic being has tried to wield it!");
	tell_room(ETP,"%^RED%^Ragnarok explodes into flames and disappears!");
	tp->do_damage(TP->return_target_limb(),(100));
     TP->add_attacker(TO);
     TP->continue_attack();
     TP->remove_attacker(TO);
	TO->remove();
	return 0;
    }
    write("%^RED%^Raw %^BOLD%^POWER %^RESET%^RED%^surges through your entire body!");
   ETO->set_property("evil item",1);
    return 1;
}

int removeme()
{
   ETO->set_property("evil item",-1);
   return 1;
}
void heart_beat(){
    object holder, env;
    env = ETO;
    if(!objectp(ETO)) return;
    if(objectp(env) && living(env) && interactive(env)){
        holder = env->query_name();
        } else {
        return;
    }
    if(holder != owner){
	tell_object(env,"The Ragnarok glows in fury as it realizes you aren't its owner and it disappears!");
        TO->remove();
        } else {
        return;
    }
}
int quake(object ob){
    int roll, roll1;
    roll=random(100)+1;
    roll1=random(20)+1;
    if(!objectp(ob)) return random(5);
    if(roll < 11){
	tell_object(ob,"%^BOLD%^YELLOW%^You are knocked to the ground from the force of Ragnarok!");
	tell_room(ETO,"%^BOLD%^YELLOW%^"+ob->query_cap_name()+" is knocked to the ground from the force of Ragnarok!",ob);
	ob->set_paralyzed(random(10)+10,"You are struggling to get up!");
    }
    if(roll > 49 && roll < 60){
	tell_room(ETO,"%^RED%^Ragnarok cackles with glee as it draws blood!");
	ob->do_damage(ob->return_target_limb(),roll_dice(2,4));
    }
    if(roll > 59 && roll < 80){
	if(roll1 > 18){
	    tell_room(ETO,"%^BLUE%^Ragnarok roars with power!");
	    ob->do_damage(ob->return_target_limb(),roll_dice(2,6));
	    } else {
	    tell_room(ETO,"%^BOLD%^BLUE%^Ragnarok screams in fury!");
	    ob->do_damage(ob->return_target_limb(),roll_dice(1,8));
	}
    }
    if(roll > 69 && roll < 80){
	tell_object(ob,"%^GREEN%^Ragnarok slices deeply into your body!");
	tell_room(ETO,"%^GREEN%^Ragnarok slices deeply into "+ob->query_cap_name()+"'s body!",ob);
	ob->do_damage(ob->return_target_limb(),roll_dice(1,6));
    }
    if(roll > 79 && roll < 101){
	if(roll1 > 18){
	    tell_object(ob,"%^MAGENTA%^Ragnarok says%^RESET%^: THE END OF THE WORLD BEGINS NOW!");
	    tell_room(ETO,"%^MAGENTA%^Ragnarok says%^RESET%^: THE END OF THE WORLD BEGINS NOW!");
	    ob->do_damage(ob->return_target_limb(),roll_dice(1,8));
	}
    }
    if(roll > 89 && roll < 101){
	tell_object(ob,"%^BOLD%^RED%^As Ragnarok strikes you it sends an earthshattering quake throughout the room!");
	tell_room(ETO,"%^BOLD%^RED%^As Ragnarok strikes "+ob->query_cap_name()+" it sends an earthshattering quake throughout the room!",ob);
	ob->do_damage(ob->return_target_limb(),roll_dice(2,4));
    }
    return 1;
}

void init(){
   ::init();
   if(interactive(TP) && ETO == TP)
      if(!stringp(owner)) owner = TPQN;
}
