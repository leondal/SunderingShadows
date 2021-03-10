//garus.c The Old Sailor
// Coded by Lujke 15/8/2017
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"
inherit MOB + "QNPC.c";

void set_responses();
int story_stage, when_finished;
void create(){
   ::create();
   set_name("Garus, the old sailor");
   set_id( ({"garus","sailor","old sailor", "attayan"}) );
   set_short("Garus the old sailor");
   set_long("This grizzled old %^CYAN%^sailor%^RESET%^ is of"
     +" %^ORANGE%^Attayan%^RESET%^ origin. He has"
     +" %^BOLD%^%^BLACK%^scr%^RESET%^u%^BOLD%^%^BLACK%^ffy"
     +" st%^RESET%^u%^BOLD%^%^BLACK%^bbl%^RESET%^e on his"
     +" sunken cheeks. A cutlass %^RED%^scar%^RESET%^ runs"
     +" across the socket of one"
     +" %^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^y%^BOLD%^"
     +"%^WHITE%^e%^RESET%^, which has been replaced with a"
     +" %^ORANGE%^wooden replica%^RESET%^. He is somewhat"
     +" bowlegged and incorporates a bit of a limp into the"
     +" normal seafarer's rolling gait. Time and weather"
     +" have left his skin looking %^ORANGE%^leathery and"
     +" tanned%^RESET%^. He is dressed in a"
     +" %^BOLD%^%^WHITE%^loose necked shirt%^RESET%^ and"
     +" %^ORANGE%^rope-belted sailor's%^RESET%^ leggings.\n"
     +"%^BOLD%^%^WHITE%^Garus is known as an incorrigible"
     +" old bore. If you get fed up with him, you can try"
     +" 'dismiss garus' to get rid of him for a while");
   set_gender("male");
   set_race("human");
   set_alignment(8);
   set_max_hp(350);
   set_hp(query_max_hp());
   set_overall_ac(-20);
   set_class("fighter");
   set_mlevel("fighter",35);
   set_level(35);
   set_stats("wisdom",8);
   set_stats("strength",22);
   set_stats("constitution",22);
   set_stats("intelligence",15);
   set_stats("charisma",8);
   set_stats("dexterity",26);
   set_exp(60);
   set("aggressive",0);
   will_open = 1;
   story_stage = 1;
   when_finished = 0;
   set_responses();
}

void init(){
  ::init();
  add_action("dismiss_me", "dismiss");
}

int dismiss_me(string str){
  if (!id(str)) return notify_fail("If you want to dismiss Garus, you need to do it by name");
  force_me("emote Staggers off to sleep in a ditch");
  move("/d/shadowgate/void");
  "/d/atoyatl/garus_locator_d"->dismiss();
}

set_responses(){
  set_response(({"hello", "greetings", "good day", "gooday"}),
          ({"Arr, good day to ye. A foine day fer a drink and fer tha telling o' tales"}) );
  set_response(({"hello" }),
          ({"Arr, good day to ye. A foine day fer a drink and fer tha telling o' tales"}) );
  set_response(({"good day"}),
          ({"Arr, good day to ye. A foine day fer a drink and fer tha telling o' tales"}) );
  set_response(({ "gooday"}),
          ({"Arr, good day to ye. A foine day fer a drink and fer tha telling o' tales"}) );

  set_response(({"drink"}), ({"A rum fer me, if ye will. Or anythin' ye got goin, ta be fair." }) );
  set_response(({"tale", "tall tale", "tell tale"}), ({"I know a tale or two, fer sure, what with me own travels an' journeys at sea." }),  "tell_tale1" );
  set_response(({"journey", "travel", "sailing", "sea", "ocean", "oceans"}), ({"I've travelled tha seas, man an boy. But me %^BLUE%^last adventure%^RESET%^ were the wildest yet!" }) );
  set_response(({"last adventure"}), ({"It were wild indeed"  }), "tell_tale" + story_stage);
  set_response(({"lost city"}), ({"Aye, deep in the jungle, the Wemic said.", "A city, lost fer hunnerds o' years. Home to tha ghosts of tha cursed people o' tha long dead Tecqumin race" }), "give_quest");
  set_response(({"where is it", "where is danger", "where is atoyatl tepexitl", "where is the continent", "where did you land"}), ({"Well, we didn' rightly know where we was, havin' been blown off course, ye see.", "But we sailed a long way back once we'd made some repairs." , "I'm no navigat'r, but I reckon we made landfall a long way north an' east on tha' Saakrune sea"}));

}

void tell_tale1(){
  if (time()<when_finished + 2400){
    force_me("say But ah've talked enuff fer now. There'll be ears as are tired o' hearing me. Ask me agin tomorrow");
    return;
  }
  if (query_intox()<900){
    force_me("say But tha's a tale fer a well-slaked thirst. P'raps another drink'd be enough ta get me talkin?");
    return;
  }
  force_me("say Well, it were a fine mornin' after a wretched stormy night on Torm's famous dock. The sun were just spreadin pink fingers into tha sky o'er tha limpid sea when Tha Mangy Scorn set off fer Attaya, unner Cap'n Foul Spring Parch at tha helm, wi' me hangin in tha riggin like a monkey.");
  story_stage = 2;
  set_response(({"last adventure"}), ({"It were wild indeed"  }), "tell_tale" + story_stage);
  call_out("tell_tale2", 8, TP);
}

void tell_tale2(object ob){
  if(!objectp(ob) || !objectp(ETO) || !present(ob, ETO)){
    force_me("say Well, ah guess ye're not all tha' innerested, anyway");
    return;
  }
  if (query_intox()<900){
    force_me("say Ah, it's thirsty work, spinnin' tales. P'raps another drink'd be enough ta help me carry on?");
    return;
  }
  force_me("say So there we was, out on tha rollin' ocean, skewin' our way through tha waves, thinkin' all were well. What we crew didn' know were that afore we set off, Capn' Parch'd bin slaking 'er thirst in tha Black Orc Bar. Well, nuthin unusual there. Bu' tha storm were ragin' hard tha' night an when she stepped out, a %^BOLD%^%^YELLOW%^bolt o' l%^WHITE%^i%^YELLOW%^ghtn%^WHITE%^i%^YELLOW%^n'%^RESET%^ flashed thru tha %^BLUE%^night%^RESET%^ an tha %^BOLD%^%^BLACK%^roll o' thunder %^RESET%^made 'er jump. It didn' hit er tho, an no harm done, ye might think. Only, when she jumped, she stepped in a large pile o' dog shite. ");
  story_stage = 3;
  set_response(({"last adventure"}), ({"It were wild indeed"  }), "tell_tale" + story_stage);
  call_out("tell_tale3", 6, ob);
}

void tell_tale3(object ob){
  if(!objectp(ob) || !objectp(ETO) || !present(ob, ETO)){
    force_me("say Well, ah guess ye're not all tha' innerested, anyway");
    return;
  }
  if (query_intox()<900){
    force_me("say Ah, it's thirsty work, spinnin' tales. P'raps another drink'd be enough ta help me carry on?");
    return;
  }
  force_me("say An again, no harm done ye might think. She were a bit more stinky than afore, but no so's anyone'd probly notice. But our Cap'n, she's a foul-mouthed bint if ever I met one - an I met a few in my time, I kin tell ye - an' tha first words out o' her mouth were a curse agin Talos fer sendin' tha lightnin'");
  story_stage = 4;
  set_response(({"last adventure"}), ({"It were wild indeed"  }), "tell_tale" + story_stage);
  call_out("tell_tale4", 5, ob);
}

void tell_tale4(object ob){
  if(!objectp(ob) || !objectp(ETO) || !present(ob, ETO)){
    force_me("say Well, ah guess ye're not all tha' innerested, anyway");
    return;
  }
  if (query_intox()<900){
    force_me("say Ah, it's thirsty work, spinnin' tales. P'raps another drink'd be enough ta help me carry on?");
    return;
  }
  force_me("say So wha's tha' got ta do wit our journey? Well, Talos, praise as due ta 'is fearful name, don' take kindly ta mortals cursin' 'im out, an 'e sends a storm out ta meet us at sea. ");
  story_stage = 5;
  set_response(({"last adventure"}), ({"It were wild indeed"  }), "tell_tale" + story_stage);
  call_out("tell_tale5", 5, ob);
}

void tell_tale5(object ob){
  if(!objectp(ob) || !objectp(ETO) || !present(ob, ETO)){
    force_me("say Well, ah guess ye're not all tha' innerested, anyway");
    return;
  }
  if (query_intox()<900){
    force_me("say Ah, it's thirsty work, spinnin' tales. P'raps another drink'd be enough ta help me carry on?");
    return;
  }
  force_me("say An praise be ta fair Istishia, she kept us from bein' hit by tha lightnin direcly, but we were rocked by great waves, pounded by blindin' rain an wind, an blow way off course. About half tha crew were lost in tha storm, includin' tha Cap'n, an tha storm only passed after she were lost, an we were left wi' not a man-jack among us wi' a clue abowt where we was.");
  story_stage = 6;
  set_response(({"last adventure"}), ({"It were wild indeed"  }), "tell_tale" + story_stage);
  call_out("tell_tale6", 6, ob);
}

void tell_tale6(object ob){
  if(!objectp(ob) || !objectp(ETO) || !present(ob, ETO)){
    force_me("say Well, ah guess ye're not all tha' innerested, anyway");
    return;
  }
  if (query_intox()<900){
    force_me("say Ah, it's thirsty work, spinnin' tales. P'raps another drink'd be enough ta help me carry on?");
    return;
  }
  force_me("say Ah won' bore ye wi' tha tribulations o' sailin lost wi' only half a crew an' no Cap'n, but stores were gone an' we was slowly starvin' ta death when finely tha lookout spied land from tha crow's nest. An what a land it were! A continent we never knew afore, wi' dark %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ngl\%^RESET%^%^GREEN%^e%^BOLD%^s %^RESET%^risin' out o' tha blue sea.");
  story_stage = 7;
  set_response(({"last adventure"}), ({"It were wild indeed"  }), "tell_tale" + story_stage);
  call_out("tell_tale7", 7, ob);
}

void tell_tale7(object ob){
  if(!objectp(ob) || !objectp(ETO) || !present(ob, ETO)){
    force_me("say Well, ah guess ye're not all tha' innerested, anyway");
    return;
  }
  if (query_intox()<900){
    force_me("say Ah, it's thirsty work, spinnin' tales. P'raps another drink'd be enough ta help me carry on?");
    return;
  }
  force_me("say An most folks won' believe me, but I tell ye, we made lan'fall on tha fabled continent o' Atoyatl Tepexitl - wha' tha' common folk used ta jus' call Danger! An' there we foun' a colony o' Wemics who were frienly an' helped us ta re-equip our ship, an work out where we were. But there were dangers there too! A haunted %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ngl\%^RESET%^%^GREEN%^e%^RESET%^, wi' walkin' plants an' rumours o' a %^BOLD%^%^CYAN%^lost city%^RESET%^ far inside. Tha Wemic even tol' tales o' great treasures ta be had, an a fountain o' youth ta be found!");
  story_stage = 8;
  set_response(({"last adventure"}), ({"It were wild indeed"  }), "tell_tale" + story_stage);
  call_out("tell_tale8", 7, ob);
}

void tell_tale8(object ob){
  if(!objectp(ob) || !objectp(ETO) || !present(ob, ETO)){
    force_me("say Well, ah guess ye're not all tha' innerested, anyway");
    return;
  }
  if (query_intox()<900){
    force_me("say Ah, it's thirsty work, spinnin' tales. P'raps another drink'd be enough ta help me carry on?");
    return;
  }
  force_me("But I tell ye, we didn' wan' tha risk o' lookin too far inside. It were a scary place, deservin' o' its name. I wouldn' go back, no' fer any money");
  story_stage = 9;
  set_response(({"last adventure"}), ({"It were wild indeed"  }), "tell_tale" + story_stage);
  when_finished = time();
}

void tell_tale9(){
  force_me("say well, lemme see");
  if (time() - 10000 > when_finished){
    story_stage = 1;
    tell_tale1();
  }
  force_me("say Ah, I've talked enuff fer one day. Ask me agin later");
}

void  receive_given_item(object ob){
  int drunkness;
  if (ob->id("drink")){
    drunkness = query_intox();
    force_me("drink drink");
    if (query_intox() > drunkness){
      call_out("wipe_lips",1, ob);
    } else {
      call_out("spit", 1);
    }
  }
}



void spit2(){
  force_me("say Talos teeth! Ye tryin' ta poison me? Sea-dogs sail on tha water - they don' drink tha fekkin stuff!");
}

void spit(){
  force_me("emote spits the drink all down the front of his shirt");
  call_out("spit2", 1);
}

void wipe_lips(object ob){
  force_me("emote wipes his lips");
  if (query_intox()>900){
    call_out("tell_tale" + story_stage, 2, ob);
  } else {
    force_me("say Ahh, that's tha' stuff! Chance o' another, ta help an ol' sea dog feel like yappin?");
  }
}

void give_quest(){
  object * critters;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  critters = all_living(ETO);
  count = sizeof(critters);
  if (count<1){
    return;
  }
  for (i=0;i<count;i++){
    if (!interactive(critters[i])){
      continue;
    }
    EVENT_RECORDS_D->record_event(critters[i]->query_name(), "Heard about the Tecqumin", time());
  }
}
