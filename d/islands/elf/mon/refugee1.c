#include <std.h>
#include "../elf.h"
inherit WEAPONLESS;

int head_home;

void create()
{
        ::create();
        set_name("elven refugee");
        set_short("%^RESET%^%^CYAN%^A %^BOLD%^%^BLACK%^tir%^BLUE%^e%^BLACK%^d %^RESET%^%^CYAN%^and %^ORANGE%^d%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^y %^RESET%^%^GREEN%^elven woman%^RESET%^");
        set_id(({"elf","refugee","citizen","elven refugee"}));
        set_long(
"This elven woman's eyes are sunken.  Her hands, arms, legs and face are"+
" covered in dirt, bruises and scratches. Her clothing is torn and frayed"+ 
" and reeks of sweat and blood. If you look more closely at her you might"+ 
" notice some of her garments have a human style about them, like her worn"+ 
" leather shoes with hard soles and a heel or the oversized belt with a"+ 
" too-big-for-an-elf metal buckle.  The green belt pouch hanging on her"+ 
" hip is definitely elven in design and seems to be full of waybread.  "+
" She holds a half chewn piece of the bread in her dirty fingers almost as"+ 
" if it was more precious than gold.  Dried up tear tracks can be seen"+ 
" constrasted by the layers of filth on her face. Her lips hold a secret"+ 
" smile amidst her tragic appearance.");
        set_gender("female");
        set_race("elf");
        set_hd(1,5);
        set_exp(1);
        set_emotes(10,({
        "The female elf notices you approaching and slips behind a nearby tree in the grove with a wimper.",
        "The female elf sings a maudlin tune filled with sorrow.",
        "The female elf crouches down and listens for danger.",
        "The female elf pulls out some more waybread and eats it almost savagely.",  
        "The female elf searches through the area.",  		
        }),0);
        command("message in walks in with a frightened look on her face.");
        command("message out darts off to the");
        command("speech speak with a frightened voice");
        set_speed(9);
        call_out("head_home",400+random(100));
		set_base_damage_type("bludgeoning");
}

int head_home(){
  if(!objectp(ETO)) return 0;
  if(!objectp(TO)) return 0;
        tell_room(ETO,"%^BOLD%^%^GREEN%^The elf departs back to her home.");
        TO->move("/d/shadowgate/void");
        destruct(TO);
        return 1;
}