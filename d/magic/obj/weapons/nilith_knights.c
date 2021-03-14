#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create(){
   ::create();
   set_name("Lurid Splendor");
   set_id(({"sword","weapon","gold sword","golden sword","splendor",
"lurid splendor","kilij","gold kilij","golden kilij"}));
   set_obvious_short("%^RESET%^%^BLUE%^g%^BOLD%^%^BLUE%^e%^CYAN%^m%^RESET%^%^GREEN%^"
"-%^BOLD%^%^GREEN%^s%^YELLOW%^t%^RESET%^%^ORANGE%^u%^RED%^d"
"%^BOLD%^%^RED%^d%^RESET%^%^MAGENTA%^e%^BLUE%^d %^YELLOW%^g%^WHITE%^o"
"%^YELLOW%^l%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^e%^YELLOW%^n "
"%^RESET%^%^WHITE%^k%^BOLD%^i%^BLACK%^l%^RESET%^%^WHITE%^i"
"%^BOLD%^%^BLACK%^j%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^L%^GREEN%^u%^BLACK%^r"
"%^RESET%^%^WHITE%^i%^BOLD%^d %^BLACK%^Sp%^BLUE%^l%^RESET%^%^WHITE%^"
"e%^BOLD%^%^BLACK%^n%^RED%^d%^CYAN%^o%^BLACK%^r%^RESET%^");
   set_long("%^YELLOW%^The blade of this opulent weapon is forged "
"from solid gold, inlaid with %^BLACK%^s%^RESET%^%^WHITE%^w%^BOLD%^i"
"%^BLACK%^r%^RESET%^%^WHITE%^l%^BOLD%^i%^BLACK%^n%^RESET%^%^WHITE%^g "
"%^RED%^a%^BOLD%^%^BLACK%^g%^RESET%^%^RED%^a%^BOLD%^%^RED%^t"
"%^RESET%^%^RED%^e %^YELLOW%^in its blood groove. The blade is similar"
" to a scimitar or cutlass; slim, curved, and gradually wider toward"
" the point of the blade, but the stabbing edge has a slight bulge "
"on the sides several inches down its length, adding a strange weight"
" to the weapon. Some arcane force took part in the creation of this"
" armament, as the blade is melded seamlessly with a hilt that seems"
" to be a humanoid %^WHITE%^femur%^YELLOW%^, its hip-joint end "
"evidently serving as the pommel. Various tiny, starburst-cut "
"%^BLUE%^g%^CYAN%^em%^GREEN%^st%^YELLOW%^on%^RED%^e%^MAGENTA%^s "
"%^YELLOW%^glint from an otherwise simple-looking crossguard, "
"forming a pair of lines down the handle to end in a whorl of "
"%^RESET%^%^RED%^bl%^BOLD%^%^RED%^o%^BLACK%^o%^RESET%^%^RED%^dst"
"%^BOLD%^%^RED%^o%^RESET%^%^RED%^ne %^YELLOW%^marbled into the "
"pommel.%^RESET%^");
   set_value(0);
   set_damage_type("slashing");
   set_hit((:TO,"hit_func":));
}

int hit_func(object targ){
   targ = ETO->query_current_attacker();
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(10)){
     tell_object(ETO,"%^BOLD%^%^BLACK%^A sickening %^RED%^crunch"
" %^BLACK%^rings out as your weapon seems to %^RESET%^%^WHITE%^"
"pass %^BOLD%^%^BLACK%^right through "+targ->QCN+"%^BOLD%^%^BLACK%^,"
" leaving no obvious injury beyond a brief look of anguish!");
     tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s blade "
"seems to pass right through you like a %^RESET%^%^CYAN%^ghost,"
" %^BOLD%^%^BLACK%^but the agonizing %^RED%^fire %^BLACK%^in "
"the %^WHITE%^bo%^RESET%^ne%^BOLD%^s %^BLACK%^that crossed its "
"path tell you otherwise!");
     tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A sickening "
"%^RED%^crunch %^BLACK%^rings out as "+ETO->QCN+"'s weapon seems to pass through "+targ->QCN+"'s "
"flesh like a %^RESET%^%^BLUE%^sp%^CYAN%^e%^BLUE%^cter"
"%^BOLD%^%^BLACK%^!",({ETO,targ}));

     return random(4)+8;
   }
}
