#include <std.h>
#include <daemons.h>
#include <standards.h>
inherit DAEMON;

int repair(string str, object player, object what, object env, int count);
void send_message(object player,string type);

int help(){             
  int i;
  write("%^YELLOW%^Syntax: repair <object>%^RESET%^\n\n"
"%^BOLD%^%^WHITE%^Allows the repair of equipment based on the appropriate skill, ie. rings can be repaired by a "
"jeweller, leather armor by a leatherworker, etc.  Higher skill ranks will allow the repair of magical items, but "
"failure at a skill check can damage the item in question.\n"
"As a guideline, to effectively repair items intended for your level, we recommend splitting your points over no "
"more than 1-2 crafting skills. However if you want to work on lower-level items, you could potentially split points "
"over more than this.\n\n"
"%^BOLD%^%^CYAN%^Related helpfiles: %^WHITE%^skills, various craft skill helpfiles (help skillname)%^RESET%^");
  return 1;
}

int cmd_repair(string str){
  object what;
  string mytype;

  if (!str) return help();
  if (TP->query_hidden()) {
    if (objectp(what=present("TSR80",TP))) what->force_cancel();
    what = 0;
  }
  if(TP->query_magic_hidden()) return notify_fail("You can't even see your own hands to work!\n");
  if (sizeof((object *)TP->query_attackers())) return notify_fail("You're in combat, let's not do that now.\n");
  if (TP->query_property("working")) return notify_fail("You are already "+(string)TP->query_property("working")+".\n");
  what = present(str,TP);
  if (!objectp(what)) what = present(str,environment(TP));
  if (!objectp(what)) return notify_fail("No "+str+" found.\n");
  if (what->query_worn() || what->query_wielded())
    return notify_fail("You need to not be so attached to the item you're working on.\n");
  if (!what->query_property("repairtype") && !what->is_instrument() && !what->is_armor() && !what->is_weapon())
    return notify_fail("You can't repair that.\n");
  if (what->query_property("no repair")) return notify_fail("You can't repair that.\n");
  TP->set_property("working","repairing");
  call_out("repair",2,str,TP,what,ETP,1);
  return 1;
}

int repair(string str, object player, object what, object env, int count){
    int myskill, i, diff, variant, state;
    string *oldtype, type;

    if (!objectp(player)) return 1;
    if (sizeof(player->query_attackers())) {
        player->remove_property("working");
        return tell_object(player,"You're in combat let's not do that now.\n");
    }
    if (env != environment(player)) {
        player->remove_property("working");
        return tell_object(player,"You've moved since starting.  You really can't do repairs while moving about.\n");
    }
    if (!objectp(what) || (!objectp(present(what,player)) && !objectp(present(what,env)))) {
        player->remove_property("working");
        return tell_object(player,"The item you're repairing is gone.");
    }

// time to pick up the skill rank. If it has an array of potential skills to use, pick the highest.
    myskill = 0;
    if(sizeof(what->query_property("repairtype"))) {
      oldtype = ({});
      if(pointerp(what->query_property("repairtype")))
      {
        oldtype += (string *)what->query_property("repairtype");
      }
      else
      {
          oldtype += ({ what->query_property("repairtype") });
      }
      for(i = 0;i<sizeof(oldtype);i++) {
        switch(oldtype[i]) {
          case "armorsmith":
          if(myskill <= player->query_skill("craft, armorsmith")) {
            myskill = player->query_skill("craft, armorsmith");
            type = "armorsmith";
          }
          break;
          case "jewel":
          if(myskill <= player->query_skill("craft, jeweller")) {
            myskill = player->query_skill("craft, jeweller");
            type = "jewel";
          }
          break;
          case "tailor":
          if(myskill <= player->query_skill("craft, tailor")) {
            myskill = player->query_skill("craft, tailor");
            type = "tailor";
          }
          break;
          case "weaponsmith":
          if(myskill <= player->query_skill("craft, weaponsmith")) {
            myskill = player->query_skill("craft, weaponsmith");
            type = "weaponsmith";
          }
          break;
          case "woodwork":
          if(myskill <= player->query_skill("craft, woodworker")) {
            myskill = player->query_skill("craft, woodworker");
            type = "woodwork";
          }
          break;
          case "leatherwork":
          if(myskill <= player->query_skill("craft, leatherworker")) {
            myskill = player->query_skill("craft, leatherworker");
            type = "leatherwork";
          }
          break;
          default:
              tell_object(player,"This object doesn't seem to have a "
                  "repair type set, please contact a wiz.");
              return 1;
        }
      }
    }
// if it doesn't have an array, just grab the appropriate skill
    else {
      if(what->is_instrument()) {
        myskill = player->query_skill("craft, woodworker");
        type = "woodwork";
      }
      if(what->is_weapon()) { //weaponsmith or woodwork, figure a split
        myskill = player->query_skill("craft, weaponsmith");
        type = "weaponsmith";
      }
      if(what->is_armor()) {
        switch(what->query_type()) {
          case "ring": case "bracer": case "sheath": case "jewelry":
          myskill = player->query_skill("craft, jeweller");
          type = "jewel";
          break;
          case "clothing":
          myskill = player->query_skill("craft, tailor");
          type = "tailor";
          break;
          case "leather": case "thiefshield":
          myskill = player->query_skill("craft, leatherworker");
          type = "leatherwork";
          break;
          case "chain": case "armor": case "armour": case "shield": case "plate":
          myskill = player->query_skill("craft, armorsmith");
          type = "armorsmith";
          break;
          default:
          tell_object(player,"You have an invalid-type wearable, please contact a wiz with this message.");
          player->remove_property("working");
          return 1;
          break;
        }
      }
    }

    send_message(player,type);
    if (count < (roll_dice(1,20) - myskill)) {
      call_out("repair",random(4)+2,str,player,what, env, count+=(roll_dice(1,4)));
      return 1;
    }

    player->remove_property("working");
    myskill += roll_dice(1,20);
    diff = (int)what->query_property("enchantment")*4; // caps out at DC28 for +7 current max gear. N, 4/17.
    if(diff < 0) diff = diff*(-1);
    diff += 10;
    variant = (myskill - diff)*2;
    if(variant > 50) variant = 50;
    if(variant < -30) variant = -30; // don't allow them to do more than 30% damage per repair

    state = what->query_overallStatus();

//    tell_object(player,"Debugging time: skill in use is "+type+" to repair "+str+". Skill selected at "+myskill+" (with d20 bonus), difficulty of "+diff+" which gives a variant (capped) of "+variant+".");

    state += variant;
    if(state > 100) state = 100;
    if(state < 0) state = 0; // don't let them set an item beyond 100% or 0% status.
    what->set_overallStatus(state);

    if(variant < 0) {//failed
      tell_room(environment(player),"It appears that more harm than good has been done to the "+str+".");
      if(state == 0) {
        tell_room(environment(player),"The "+str+" is too badly damaged and simply falls apart.");
        what->remove();
      }
      return 1;
    }
    if(variant == 0) {//no diff
      tell_room(environment(player),"You can see no noticeable improvement to the state of the "+str+".");
      return 1;
    }
    if(state == 100) tell_room(environment(player),"The "+str+" looks as good as new.");
    else tell_room(environment(player),"The "+str+" appears to be in better shape.");
    return 1;
}

void send_message(object player, string type){
    if(type == "armorsmith") {
      switch(random(5)){
      case 0:
        tell_object(player,"%^BOLD%^You work on the armor with a small hammer.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" works on the armor with a small hammer.",player);
        break;
      case 1:
        tell_object(player,"%^BOLD%^You work on the armor with an oilcloth.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" works on the armor with an oilcloth.",player);
        break;
      case 2:
        tell_object(player,"%^BOLD%^You resize the armor.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" resizes the armor.",player);
        break;
      case 3:
        tell_object(player,"%^BOLD%^You carefully hammer out a dent in the metal.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" hammers out a dent in the metal armor.",player);
        break;
      case 4:
        tell_object(player,"%^BOLD%^You replace a damaged rivet.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" replaces a damaged armor rivet.",player);
        break;
      }
      return;
    }
    if(type == "leatherwork") {
      switch(random(5)){
      case 0:
        tell_object(player,"%^BOLD%^You reinforce some frayed stitching.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" reinforce some frayed leather stitching.",player);
        break;
      case 1:
        tell_object(player,"%^BOLD%^You work on the armor with an oilcloth.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" works on the armor with an oilcloth.",player);
        break;
      case 2:
        tell_object(player,"%^BOLD%^You resize the armor.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" resizes the armor.",player);
        break;
      case 3:
        tell_object(player,"%^BOLD%^You apply some new leather to the armor.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" applies some new leather to the armor.",player);
        break;
      case 4:
        tell_object(player,"%^BOLD%^You apply a thin coat of protective wax to the leather.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" applies a thin coat of protective wax to the leather.",player);
        break;
      }
      return;
    }
    if(type == "woodwork") {
      switch(random(5)){
      case 0:
        tell_object(player,"%^BOLD%^You polish the wood with lemon oil.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" polishes the wood with lemon oil.",player);
        break;
      case 1:
        tell_object(player,"%^BOLD%^You sand away a few stray wood splinters.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" sands away a few stray wood splinters.",player);
        break;
      case 2:
        tell_object(player,"%^BOLD%^You use some resin to repair a gouge in the wood.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" uses some resin to repair a gouge in the wood.",player);
        break;
      case 3:
        tell_object(player,"%^BOLD%^You carefully reshape the wood.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" carefully reshapes the wood.",player);
        break;
      case 4:
        tell_object(player,"%^BOLD%^You use a small blade to resculpt the worn etchings in the wood.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" uses a small blade to resculpt the worn etchings in the wood.",player);
        break;
      }
      return;
    }
    if(type == "jewel") {
      switch(random(5)){
      case 0:
        tell_object(player,"%^BOLD%^You use the small hammer to reshape the metal back to its original size.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" uses the small hammer to reshape the metal back to its original size.",player);
        break;
      case 1:
        tell_object(player,"%^BOLD%^You lace a wire around the metal, strengthening the weak joint.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" laces a wire around the metal, strengthening the weak joint.",player);
        break;
      case 2:
        tell_object(player,"%^BOLD%^You inspect and start to repair a problem with the gem mounting.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" inspects and starts to repair a problem with the gem mounting.",player);
        break;
      case 3:
        tell_object(player,"%^BOLD%^You remove the weak and damaged sections of metal.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" removes the weak and damaged sections of metal.",player);
        break;
      case 4:
        tell_object(player,"%^BOLD%^You buff the metal to a shine.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" buffs the metal to a shine.",player);
        break;
      }
      return;
    }
    if(type == "tailor") {
      switch(random(5)){
      case 0:
        tell_object(player,"%^BOLD%^You work on the clothing with a fine needle.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" works on the clothing with a fine needle.",player);
        break;
      case 1:
        tell_object(player,"%^BOLD%^You work on the clothing with a piece of reinforcing backing.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" adds a piece of cloth to reinforce the clothing.",player);
        break;
      case 2:
        tell_object(player,"%^BOLD%^You resize the clothing.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" resizes the clothing.",player);
        break;
      case 3:
        tell_object(player,"%^BOLD%^You work on the clothing with a heavy needle and strong thread, to reinforce the seams.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" works on the clothing with a heavy needle and strong thread to reinforce the seams.",player);
        break;
      case 4:
        tell_object(player,"%^BOLD%^You unpick a few damaged threads and then carefully replace them.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" unpicks a few damaged threads and then carefully replaces them.",player);
        break;
      }
      return;
    }
    if(type == "weaponsmith") {
      switch(random(5)){
      case 0:
        tell_object(player,"%^BOLD%^You work on the weapon with a whetstone.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" works on the weapon with a whetstone.",player);
        return;
      case 1:
        tell_object(player,"%^BOLD%^You work on the weapon with an oilcloth.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" works on the weapon with an oilcloth.",player);
        return;
      case 2:
        tell_object(player,"%^BOLD%^You grind the weapon with a heavy stone.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" grinds the weapon with a heavy stone.",player);
        return;
      case 3:
        tell_object(player,"%^BOLD%^You apply some new leather to the weapon.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" applies some new leather to the weapon.",player);
        return 1;
      case 4:
        tell_object(player,"%^BOLD%^You carefully hammer out a dent in the metal.");
        tell_room(environment(player),"%^BOLD%^"+player->QCN+" hammers out a dent in the metal weapon.",player);
        break;
      }
      return;
    }
    tell_object(player,"%^BOLD%^Your item has an invalid type, please notify an immortal.");
    return;
}
