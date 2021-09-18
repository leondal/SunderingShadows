//NOT ACTIVELY USED

//This way we can do TP->is_valid_skill(skillname)
//to see if something is actually a valid skill or not - Saide
int is_valid_skill(string str);

int query_highest_level();
int true_query_highest_level();
// ******** New(er) Experience Management Functions Here ******
void __internal_add_exp(int exp);
// This was the old add_exp and now provides conversion of old characters
// to newer format (split,spelled out XP between the two classes)

// These three are "shim" functions.
void add_exp(int exp);
// void set_general_exp(string type, int x);
void add_general_exp(string type, int x);
int general_exp_adjust_perc(int perc);
int class_exp_adjust_perc(string myclass, int perc);


int use_XP_tax(object who, int exp)
{
    mapping _IRS;
    float adjustment;
    int percent, antimeter;
    if(!objectp(who)) return exp;

    _IRS = who->query_XP_tax();
    if(!mapp(_IRS)) return exp;
    if (exp < 0) return exp;
    // No tax on negative XP.
    adjustment = to_float(exp);

    if ( (percent = _IRS["tax"]["general"]) >= 100)
    {
        log_file("player/tax",TO->query_cap_name()+": General XP taxed to 1.");
        return 1;
    }
    else if (percent)
    {
        adjustment -= adjustment * to_float(percent)/100;
    }

    if (_IRS["tax"]["leveled"]["level"] > query_lowest_level() )
    {
        if ( (percent = _IRS["tax"]["leveled"]["percent"] ) >= 100)
        {
            log_file("player/tax",TO->query_cap_name()+": XP taxed (level-based) to 1.");
            return 1;
        }
        else if (percent)
        {
            adjustment -= adjustment * to_float(percent)/100;
        }
    }

    if ( (antimeter = _IRS["tax"]["metered"]["meter"]) > 0)
    {
        if ((percent = _IRS["tax"]["metered"]["percent"]) >= 100)
        {
            _IRS["tax"]["metered"]["meter"] -= 1;
            log_file("player/tax",TO->query_cap_name()+": XP taxed (meter-based) to 1.");
            return 1;
        }
        else
        {
            if (percent >= 0)
            { // Tax
                if (antimeter >=  (adjustment * to_float(percent)/100) )
                {
                    antimeter = adjustment * to_float(percent)/100;
                    adjustment -= to_float(antimeter);
                    _IRS["tax"]["metered"]["meter"] -= antimeter;
                }
                else
                {
                    _IRS["tax"]["metered"]["meter"] = 0;
                    adjustment -= antimeter * 100 / to_float(percent);
                    adjustment += to_float(antimeter);
                }
            }
            else
            { // rebate, just give them the benefit of the whole thing.
                _IRS["tax"]["metered"]["meter"] -= antimeter;
                adjustment += adjustment * to_float(percent)/100;
            }
        }
    } // End Metered Section
    return to_int(adjustment);
}

int use_XP_rest(int exp)
{
    float adjustment;
    int percent;

    if(percent = _IRS["tax"]["timed"]["percent"])

  return exp;
  // temporary ;
}

void log_exp(int x, string type, object tmp, object who)
{
    if(!objectp(who)) return;
    if(!userp(who)) return;
    if((x > 1000 || x < -1000))
    {
        log_file("player/exp", "<<<"+
            (string)who->QN+" received "+x+" ("+type+")exp from "+ (string)previous_object()->query_name()+"\n");
        log_file("player/exp",
            "  (creator = "+previous_object()->query_creator()+")\n"+
            "  (uid: "+getuid(previous_object())+" "+file_name(previous_object())+")\n");
        if (objectp(tmp) && (tmp != previous_object()))
            log_file("player/exp",
            "  (creator = "+tmp->query_creator()+")\n"+
            "  (uid: "+getuid(tmp)+" "+file_name(tmp)+")\n");

        log_file("player/exp", ctime(time()) + ">>>\n");
    }
}

int resolve_auto_tax(object who, int exp)
{
    int days,hours,time,limit,bonuslimit,level,mod,perc;
    string *classes=({});
    if(!objectp(who)) { return exp; }
    if(!userp(who)) { return exp; }
    if(avatarp(who)) { return exp; }
    if(exp < 1) { return exp; }
    if((int)who->query_property("ignore tax")) return exp; //installed to stop imm-granted exp going awry. Nienne, 04/10
    if(!intp(level=(int)who->query_adjusted_character_level())) { return exp; }
    if(!level) { return exp; }

    time    = (int)who->query_age();
    hours   = time/3600;     // total hours

    limit = LEVEL_LIMIT[level];
    if(!limit) { return exp; }

    // eg, level requires 24 hours ptime
    // 29 =   24  + 1

    bonuslimit = limit*2; //used for the reverse-tax; once players reach 200% required playtime it will start to kick in.
    if(hours > bonuslimit) {
      // next bit gives the percent above 100%, which will multiply their exp
      // it will range from 101 to 185 capped, to give a bonus extra exp of 1-85%
      perc = ((hours / limit) * 100) - 100;
      if(perc < 101) return exp; // less than 101% = normal exp return.
      if(perc > 185) perc = 185; // capped 85% bonus.
      set("autotax",(-1)*(perc-100));

      //then return corresponding increased exp; exp*bonus*0.01 (to convert to a percentage)
      return to_int(exp * (perc *0.01));
    }

    //going back to non-reverse-tax calcs, for normal or taxed exp.
    limit = limit + 1; // was +5; not sure why we were adding an extra 5 hours to each level's PT reqs?

    // if this is set here, it will not clear an autotax once a person catches up -Ares
    //if(hours > limit) { return exp; }

    // eg player has only 18 hours ptime
    // 11 =  29  -   18

    mod = limit - hours;

    // eg mod becomes 55
    // 55 = 11 * 5

    mod = mod * 5;

    if(mod > 85) { mod = 85; }

    if(hours > limit) { mod = 0; }

    set("autotax",mod);

    //eg mod becomes 45
    //45 = absolute_value(55 - 100)

    mod = absolute_value(mod - 100);

    //eg mod is 45 and original exp = 1000
    //      450 =   1000 * (.45 = 45 * 0.01)

    return to_int(exp * (mod *0.01));
}

void add_exp(int exp)
{
// adding to stop mobs from getting out of control fighting each other *Styx* 12/25/05
    if(!objectp(who)) return;
    if(!userp(who)) return;

    if(userp(who) && (exp >0) && who->query_party())
    {
        PARTY_OB->calculate_exp(who->query_party(), exp, previous_object());
        return;
    }
    if ((int)who->has_XP_levelcap() && (exp > 0))
        return;
    if ((int)who->has_XP_tax())
        exp = who->use_XP_tax(exp);
    if (who->has_XP_rest())
        exp = who->use_XP_rest(exp);
    //going to change the way tax works - should remain 0 for everyone, unless
    //the have been granted a bonus - which should fall off after x amount of time - Saide
    //exp = resolve_auto_tax(exp);
    exp = who->exp_buffer(exp);

    log_exp(exp,"add",0);
    who->__internal_add_exp(exp);

}

void party_exp(int exp, object tmp){

  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  if (has_XP_rest())
    exp = use_XP_rest(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);

  log_exp(exp,"party", tmp);
  __internal_add_exp(exp);

}

void fakeparty_exp(int exp, object tmp){

  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  if (has_XP_rest())
    exp = use_XP_rest(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);

  log_exp(exp,"~add", tmp);
  __internal_add_exp(exp);

}

void fix_exp(int exp, object tmp) {
  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);
  log_exp(exp,"fix", tmp);
  __internal_add_exp(exp);

}

void quest_exp(int exp, object tmp) {
  if (has_XP_levelcap() && exp > 0)
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);
  log_exp(exp,"quest", tmp);
  __internal_add_exp(exp);

}

void partyquest_exp(int exp, object tmp){

  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);

  log_exp(exp,"partyquest", tmp);
  __internal_add_exp(exp);

}

void repair_exp(int exp, object tmp) {
  log_exp(exp,"repair",tmp);
  __internal_add_exp(exp);
}

//void set_general_exp(string type, int exp){
// Placeholder.
//}

void add_general_exp(string type, int exp){
  if (has_XP_levelcap() && exp >0)
      return;
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);
  ::add_general_exp(type, exp);
}

int class_exp_adjust_perc(string class, int perc) {
  float value;
  int exp;

  if (!intp(perc)) return 0;
  if ( (perc > 101) || (perc < -101) ) return 0;
  if (member_array(class, TO->query_classes()) == -1 )  return 0;
  if(avatarp(TO)) return 0;
  value = perc / 100.0;
  exp=get_general_exp(class);
  value = exp * value;
  exp = to_int(floor(value));
  add_general_exp(class, exp);
  if (perc < 0) resetLevelForExp(0);
  return perc;
}

int general_exp_adjust_perc(int perc) {
  string * classes;
  string class;
  int loop;
  object tmp;
  int oldexp;
  int returnval = 0;

  if (!intp(perc)) return 0;
  if ( (perc > 101) || (perc < -101) ) return 0;
  if(avatarp(TO)) return 0;

  if (class = get_dual_class()) {
      classes = ({class});
  } else {
      classes = TO->query_classes();
  }
  tmp = PO;
  oldexp = TO->query_exp();
      log_file("player/exp",">>> "+
               query_name()+" adjusted "+perc+"% exp from "+(string)tmp->query_name()+"\n");
      log_file("player/exp",
               "  (creator = "+tmp->query_creator()+")\n"+
               "  (uid: "+getuid(tmp)+" "+file_name(tmp)+": "+
               ctime(time())+"\n");
  if(!TO->query("new_class_type"))
  {
      for(loop=0;loop<sizeof(classes);loop++)
      {
        returnval += class_exp_adjust_perc(classes[loop],perc);
      }
  }
  else
  {
      returnval += class_exp_adjust_perc(classes[0],perc);
  }
  returnval = returnval / sizeof(classes);
      log_file("player/exp","<<< "+
               query_name()+" adjusted "+((int)TO->query_exp() - oldexp)+" exp. \n");
  return returnval;
}


mapping query_IRS() { return _IRS; }

void set_XP_tax(int percent, int duration) {
  init_IRS();
  if (duration == 0) {
    _IRS["tax"]["general"] = percent;
   return;
  }
  if (duration > 0) {
    _IRS["tax"]["metered"]["percent"]=percent;
    _IRS["tax"]["metered"]["meter"]=duration;
  } else {
    duration *= -1;
    _IRS["tax"]["leveled"]["percent"]=percent;
    _IRS["tax"]["leveled"]["level"]=query_lowest_level()+duration;
  }
}

void remove_XP_tax(string which){
  switch(which) {
  case "metered":
    if (!mapp(_IRS) || !mapp(_IRS["tax"]) || !mapp(_IRS["tax"]["metered"]))
      init_IRS();
    _IRS["tax"]["metered"]["percent"] = 0;
    _IRS["tax"]["metered"]["meter"] = 0;
    break;
  case "level":
    if (!mapp(_IRS) || !mapp(_IRS["tax"]) || !mapp(_IRS["tax"]["leveled"]))
      init_IRS();
    _IRS["tax"]["leveled"]["percent"] = 0;
    _IRS["tax"]["leveled"]["level"] = -1;
    break;
  case "all":
    remove_XP_tax("metered");
    remove_XP_tax("level");
  case "general":
  default:
    if (!mapp(_IRS) || !mapp(_IRS["tax"])) init_IRS();
    _IRS["tax"]["general"] = 0;
    break;
  }
}

int has_XP_levelcap() {
  int levelcap;
  levelcap = query("no advance");

  // Support for player-initiated levelcaps comes in here.
  // Just check if levelcap is greater than PI_levelcap

  if(OB_ACCOUNT->is_high_mortal((string)TO->query_true_name())) { return 0; }
  if (levelcap < 0) levelcap = 0;
  if (levelcap && (levelcap <= query_highest_level()))
    return 1;
  return 0;
}

int query_exp() {

    int exp,i,s;
    string *cls;

    if(TO->query("new_class_type")) { return ::query_exp(); }

    if (!userp(TO) || (!SPLIT_EXP && query_name()!="test")) {
        return ::query_exp();
    }

    if(TO->query("new_class_type"))
    {
        return ::query_exp();
    }

    s = sizeof(classes);
    //conversion!!!!
    if (intp(::query_exp()) && s) {
        exp = ::query_exp();
        ::set_exp(0);
        exp = exp/s;
        for (i=0;i<s;i++) {
            set_general_exp(classes[i],exp);
        }
    }
    if (get_dual_class()) {
        return get_general_exp(get_dual_class());
    } else {
        exp = 0;
        cls = query_classes();
        s = sizeof(cls);
        for (i=0;i<s;i++) {
            exp += get_general_exp(cls[i]);
        }
    }
    return exp;
}

int query_lowest_level(){
  int i,hold,num;
  string *cls;
  if(!classes || !sizeof(classes)) return 0;
  if(!mlevels ||mlevels == ([])) return 0;
   if(!classes || classes == ({})) return 0;

   if(TO->query("new_class_type") && !avatarp(TO)) { return query_base_character_level(); }

   cls = query_classes();
   hold = mlevels[cls[0]];
   num = hold;
  for(i=1;i<sizeof(cls);i++)
  {
    num += mlevels[cls[i]];
    if(hold > mlevels[cls[i]])
      hold = mlevels[cls[i]];
  }

  // so personas work -Ares
  if(avatarp(TO) && (num < 150 && num > hold)) { return num; }

  return hold;
}

int true_query_highest_level(){

    int i,hold, du, flag;
    if(!classes || !sizeof(classes)) return 0;
    if(!mlevels || mlevels == ([])) return 0;

    if(TO->query("new_class_type") && !avatarp(TO)) { return query_base_character_level(); }

    hold = mlevels[classes[0]];
    for(i=1;i<sizeof(classes);i++){
      if(hold < mlevels[classes[i]])
        hold = mlevels[classes[i]];
    }
    //if (!du || du >= hold) {
        return hold;
}

int query_highest_level(){
  int i,hold, du, flag,num;
  if(!classes || !sizeof(classes)) return 0;
  if(!mlevels || mlevels == ([])) return 0;
  if(!objectp(TO)) { return 0; }

  if(TO->query("new_class_type") && !avatarp(TO)) { return query_base_character_level(); }

  hold = mlevels[classes[0]];
  num = hold;
  for(i=1;i<sizeof(classes);i++)
  {
    num += mlevels[classes[i]];
    if(hold < mlevels[classes[i]])
      hold = mlevels[classes[i]];
  }
  if (get_dual_class()) {
      return mlevels[get_dual_class()];
  }
  //if (!du || du >= hold) {

  // So personas work -Ares
  if(avatarp(TO) && (num < 150 && num > hold)) { return num; }

  return hold;

  //}
  //return du;
}

int query_class_level(string str){
  if(mlevels && mlevels != ([]) && mlevels[str])
    return mlevels[str];
  return 0;
}

//Added for advance - so that drow and other races
//dont count their level_adjustment in the advance
//command - Saide
int query_base_character_level()
{
	int num, i;
	if(!sizeof(classes)) { return 0; }
	if(!TO->is_player()) { return query_highest_level(); }
	for(i = 0;i < sizeof(classes);i++)
	{
		num += query_class_level(classes[i]);
	}
	return num;
}

int query_adjusted_character_level() {
  return query_character_level();
}

int query_character_level() {
    int i,num;
    string myrace,mysubrace,file;
    if(!sizeof(classes)) { return 0; }

    if(!TO->is_player()) { return query_highest_level(); }

    for(i=0;i<sizeof(classes);i++) {
        num += query_class_level(classes[i]);
    }
// adding LA adjustment here; this is the only place it should be needed. -N, 10/10

    myrace = this_object()->query_race();
    mysubrace = (string)query("subrace");
    file = "/std/races/"+myrace+".c";
    return num;
}

int is_valid_skill(string str)
{
	if(!str) return 0;
	if(!stringp(str)) return 0;
	if(member_array(str, keys(SKILL_STATS)) != -1) return 1;
	return 0;
}

int query_true_guild_level(string str)
{
    if(str == "cleric")
    {
        if(TO->is_class("ranger"))
        {
            if(guilds[str] > (int)TO->query_class_level("ranger"))
            {
                guilds[str] = (int)TO->query_class_level("ranger");
            }
        }
        else if(TO->is_class("paladin"))
        {
            if(guilds[str] > (int)TO->query_class_level("paladin"))
            {
                guilds[str] = (int)TO->query_class_level("paladin");
            }
        }
        else if(TO->is_class("antipaladin"))
        {
            if(guilds[str] > (int)TO->query_class_level("antipaladin"))
            {
                guilds[str] = (int)TO->query_class_level("antipaladin");
            }
        }
        else
        {
            if(guilds[str] > (int)TO->query_class_level(str))
            {
                guilds[str] = (int)TO->query_class_level(str);
            }
        }
        return guilds[str];
    }

    if(guilds[str] > (int)TO->query_class_level(str))
    {
        guilds[str] = (int)TO->query_class_level(str);
    }
    return guilds[str];
}

int query_guild_level(string str)
{
    string *classes;
    int i,num = 0;

    if(!str) { return 0; }
    if(!guilds)
    {
        guilds = ([]);
        return 0;
    }

    if(TO->query("new_class_type") && sizeof((string *)TO->query_classes()))
    {
        classes = (string *)TO->query_classes();

        for(i=0;i<sizeof(classes);i++)
        {
            if(classes[i] == "ranger" || classes[i] == "paladin" || classes[i] == "antipaladin")
            {
                if(str == "cleric") { continue; }
            }
            if(classes[i] == str) { continue; }
            num += (int)TO->query_class_level(classes[i]) / 2;
        }

        return guilds[str] + num;
    }
    return guilds[str];
}


int query_max_skills()
{
    int num=0, i, mylevel, lvladj, lowskill=0, highskill=0;
    string *myclasses, file, myrace, subrace;

    myclasses = this_object()->query_classes();

    for (i = 0; i < sizeof(myclasses); i++) {
        mylevel = ((int)TO->query_class_level(myclasses[i]));
        file = DIR_CLASSES + "/" + myclasses[i] + ".c";
        if (file_exists(file)) {
            if ((int)file->skill_points() == 6) {
                highskill += mylevel;
            }else {
                lowskill += mylevel;
            }
        }
    }

    myrace = (string)TO->query_race();
    subrace = (string)TO->query("subrace");
    file = DIR_RACES+"/"+myrace+".c";

    if ((lowskill % 2) && (highskill % 2)) {
        lowskill++;
        highskill--;
    }

    num += ((lowskill/2)*4);
    num += ((highskill/2)*6);

    if (myrace == "human") {
        if (!subrace || subrace == "" ||
            (subrace != "tiefling" && subrace != "aasimar" && subrace != "dhampir" && subrace != "feytouched")) {
            num = num + 4;
        }
    }
    return num;
}

int skill_armor_mod(string *myworn)
{
   int i, modifier;
   string thetype;
   modifier = 0;
   for (i = 0; i < sizeof(myworn); i++) {
       thetype = (string)myworn[i]->query_type();
       if (thetype == "armor" || thetype == "armour") {
           modifier = -15;
       }
       if (thetype == "chain" && modifier > -4) {
           modifier = -10;
       }
       if (thetype == "leather" && !modifier) {
           modifier = -5;
       }
   }
   return modifier;
}
