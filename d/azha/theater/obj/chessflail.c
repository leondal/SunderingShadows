#include <std.h>

inherit "/d/common/obj/weapon/flail.c";

void create(){
	::create();
   	set_name("chessman's flail");
   	set_id(({"flail","chessman's flail","ebony flail","+
		""ivory flail"}));
   	set_obvious_short("%^RESET%^An%^BOLD%^ %^BLACK%^ebony"+
		"%^RESET%^ and %^BOLD%^ivory%^RESET%^ flail%^RESET%^");
   	set_short("%^BOLD%^%^WHITE%^C%^BLACK%^h%^WHITE%^e"+
		"%^BLACK%^s%^WHITE%^s%^BLACK%^m%^WHITE%^a%^BLACK%^"+
		"n%^WHITE%^'%^BLACK%^s %^WHITE%^F%^BLACK%^l"+
		"%^WHITE%^a%^BLACK%^i%^WHITE%^l %^RESET%^");
   	set_long("%^RESET%^Fashioned from %^BOLD%^ivory%^RESET%^ and"+
		" %^BOLD%^%^BLACK%^ebony%^RESET%^, this flail"+
		" has a striking appearance.  The simplicity "+
		"of the %^BOLD%^%^BLACK%^"+
		"black%^RESET%^ and %^BOLD%^white%^RESET%^"+
		" color scheme is brought to new heights with the details of "+
		"this flail.  The handle of the flail features stacked"+
		" rounded squares of %^BOLD%^%^BLACK%^ebony%^RESET%^ and "+
		"%^BOLD%^ivory%^RESET%^.  The pommel of the handle "+
		"is inlaid with an oval cabochon stone, half "+
		"%^BOLD%^ivory%^RESET%^ "+
		"half %^BOLD%^%^BLACK%^ebony%^RESET%^.  A segmented"+
		" chain made from %^BOLD%^%^BLACK%^ebony%^RESET%^ and "+
		"%^BOLD%^ivory%^RESET%^ links is connected to the handle."+
		"  The two feet long chain ends with a %^BOLD%^%^CYAN%^"+
		"crystal%^RESET%^ pawn.  The pawn, one of the pieces on"+
		" a chessboard, is rounded off to a blunt edge.  Bands of "+
		"%^BOLD%^ivory%^RESET%^ and %^BOLD%^%^BLACK%^ebony%^RESET%^"+
		" are inset into the weighted pawn.%^RESET%^\n");
   	set_lore("All the Kings' Horsemen was a novel play written by "+
		"Yaran Silverpage, a playwright who favored odd"+
		" and strange plays that pushed the boundaries.   All the "+
		"King's Horsemen was a play set on a life size chessboard."+
		"  Set in the middle of a war between two princes, this epic"+
		" play used the chessboard as the battlefield.  The two"+
		" princes are immersed in a bloody war for the throne, the "+
		"winner takes the crown while the loser received death."+
		"  While All the Kings Horsemen was a strange play at first,"+
		" the play is rich with drama and intrigue. - Pages"+
		" of Silverpage -The Avant Garde Playwright-  Damona Silverpage");
   	set_property("lore difficulty",13);
     	set_property("enchantment",3);
   	set("value",1500);
     	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
   	set_hit((:TO,"hit_func":));
   	
}
int wield_func(string str) {
      tell_object(ETO,"%^BOLD%^You grasp onto the flail's handle"+
		", feeling the cold stone in your hand. %^RESET%^");
   	tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" grasps a"+
		" black and white flail in "+ETO->QP+" hand.",ETO);
   			return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^BOLD%^%^BLACK%^You release your hold "+
		"of the flail.");
   	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" "+
      	"releases the black and white flail.",ETO);
   			return 1;
}

int hit_func(object targ)
{
    targ = ETO->query_current_attacker();
    if(!objectp(ETO)) return 1;
    if(!objectp(targ)) return 1;
    
    if(random(1000) < 175)
    {
    switch(random(50))
    {
    case 0..8:
          tell_object(ETO,"%^BOLD%^The pawn on the end of the "+
            "flail transforms into a %^BLUE%^rook%^WHITE%^,"+
            " allowing you to blast past "+
            ""+targ->QCN+"'s defenses.");
          tell_object(targ,"%^BOLD%^The pawn on "+ETO->QCN+"'s flail"+
            " transforms into a %^BLUE%^rook%^WHITE%^ just before"+
            " they blast through your defenses!");
          tell_room(environment(ETO),"%^BOLD%^The pawn on "+ETO->QCN+"'s"+
            " flail transforms into a %^BLUE%^rook%^WHITE%^ just "+
            "before the blast through"+
            " "+targ->QCN+"'s defenses.", ({ETO,targ}));
                ETO->set_property("magic",1);
                targ->cause_typed_damage(targ, "torso", roll_dice(1, 4) + 2, "bludgeoning");
                ETO->set_property("magic",-1);
        break;
        
    case 9..21:
        tell_object(ETO,"%^BOLD%^%^BLACK%^The pawn on the end of "+
            "the flail transforms into a %^RED%^knight%^BLACK%^,"+
            " allowing you to strike a solid blow at "+targ->QCN+".");
          tell_object(targ,"%^BOLD%^%^BLACK%^ The pawn on "+ETO->QCN+"'s"+
            " flail transforms into a %^RED%^knight%^BLACK%^ just "+
            "before it connects a solid blow onto you.");
          tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The pawn on "+
            ""+ETO->QCN+"'s flail transforms into a %^RED%^knight"+
            "%^BLACK%^ just before they strike a solid blow at "+
            ""+targ->QCN+".", ({ETO,targ}));
          targ->cause_typed_damage(targ, "torso", roll_dice(1, 6) + 3, "slashing");
        break;
        
    case 22..34:
        tell_object(ETO,"%^BOLD%^%^BLACK%^The pawn on the end of the"+
            " flail transforms into a %^CYAN%^bishop%^BLACK%^,"+
            " allowing you bash "+targ->QCN+".");
          tell_object(targ,"%^BOLD%^%^BLACK%^ The pawn on "+ETO->QCN+"'s"+
            " flail transforms into a %^%^CYAN%^bishop%^BLACK%^"+
            " allowing "+ETO->QO+" bash you with a well connected blow.");
          tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The pawn on "+
            ""+ETO->QCN+"'s flail transforms into a %^CYAN%^bishop"+
            "%^BLACK%^ allowing "+ETO->QO+" to bash a solid blow onto "+
            ""+targ->QCN+".", ({ETO,targ}));
          targ->cause_typed_damage(targ, "torso", roll_dice(1, 4) + 5, "divine");
            break;		
            
    case 35..45:
        tell_object(ETO,"%^BOLD%^The pawn on the end of the flail "+
            "transforms into a %^MAGENTA%^queen%^WHITE%^,"+
            " allowing you to circle around for another attack on"+
            " "+targ->QCN+".");
          tell_object(targ,"%^BOLD%^ The pawn on "+ETO->QCN+"'s flail "+
            "transforms into a %^MAGENTA%^queen%^WHITE%^ allowing "+
            ""+ETO->QO+" to circle around again for another attack"+
            " on you.");
          tell_room(environment(ETO),"%^BOLD%^The pawn on "+ETO->QCN+"'s "+
            "flail transforms into a %^MAGENTA%^queen%^WHITE%^ "+
            "allowing "+ETO->QO+" to circle back around"+
            " for a second attack on "+targ->QCN+".", ({ETO,targ}));
                ETO->execute_attack();
        break;	
        
    case 46..49:
        tell_object(ETO,"%^BOLD%^%^BLACK%^%^The pawn on the end of the"+
            " flail transforms into a %^YELLOW%^king%^BLACK%^,"+
            " leaving you open to a checkmate by "+targ->QCN+".");
          tell_object(targ,"%^BOLD%^%^BLACK%^ The pawn on "+ETO->QCN+"'s"+
            " flail transforms into a %^YELLOW%^king%^BLACK%^"+
            " giving you the chance to deal some damage back to"+
            " "+ETO->QO+"!");
          tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The pawn on "+
            ""+ETO->QCN+"'s flail transforms into a %^YELLOW%^king"+
            "%^BLACK%^ giving "+targ->QCN+" the chance strike out "+
            "at "+ETO->QCN+".", ({ETO,targ}));
                ETO->set_property("magic",1);
                ETO->cause_typed_damage(ETO, "torso", roll_dice(1, 3) + 1, "slashing");
                ETO->set_property("magic",-1);

    default:
        break;

    		
		}
    return 1;
	}
}
