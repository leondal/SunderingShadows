mapping query_XP_tax(){
  if (!mapp(_IRS) || !mapp(_IRS["tax"]))
    init_IRS();
  return _IRS["tax"];
}

int use_XP_tax(int exp)
{
  float adjustment;
  int percent, antimeter;

  if (exp < 0) return exp;
  // No tax on negative XP.
  adjustment = to_float(exp);

  if ( (percent = _IRS["tax"]["general"]) >= 100) {
      log_file("player/tax",TO->query_cap_name()+": General XP taxed to 1.");
    return 1;
  } else if (percent) {
    adjustment -= adjustment * to_float(percent)/100;
  }

  if (_IRS["tax"]["leveled"]["level"] > query_lowest_level() )
    if ( (percent = _IRS["tax"]["leveled"]["percent"] ) >= 100) {
      log_file("player/tax",TO->query_cap_name()+": XP taxed (level-based) to 1.");
      return 1;
    } else if (percent) {
      adjustment -= adjustment * to_float(percent)/100;
    }

    if ( (antimeter = _IRS["tax"]["metered"]["meter"]) > 0) {
      if ((percent = _IRS["tax"]["metered"]["percent"]) >= 100) {
       _IRS["tax"]["metered"]["meter"] -= 1;
      log_file("player/tax",TO->query_cap_name()+": XP taxed (meter-based) to 1.");
       return 1;
      } else {
        if (percent >= 0) { // Tax
         if (antimeter >=  (adjustment * to_float(percent)/100) ) {
           antimeter = adjustment * to_float(percent)/100;
           adjustment -= to_float(antimeter);
           _IRS["tax"]["metered"]["meter"] -= antimeter;
         } else {
           _IRS["tax"]["metered"]["meter"] = 0;
           adjustment -= antimeter * 100 / to_float(percent);
           adjustment += to_float(antimeter);
         }
       } else { // rebate, just give them the benefit of the whole thing.
         _IRS["tax"]["metered"]["meter"] -= antimeter;
          adjustment += adjustment * to_float(percent)/100;
       }
      }
    } // End Metered Section
    return to_int(adjustment);
}

int has_XP_tax()
{
  init_IRS();
  if (_IRS["tax"]["general"])
    return 1;
  if ( (_IRS["tax"]["metered"]["percent"])
       && (_IRS["tax"]["metered"]["meter"] > 0) )
    return 1;
  if ( (_IRS["tax"]["leveled"]["percent"])
       && (_IRS["tax"]["leveled"]["level"] > query_lowest_level()) )
    return 1;
  return 0;
}

int has_XP_rest()
{
    int when;
    if(when = __IRS["tax"]["timed"]["fall off"])
    {
        if(time() > when) return 0;
        return 1;
    }
    return 0;
}

int use_XP_rest(int exp)
{
    float adjustment;
    int percent;

    if(percent = _IRS["tax"]["timed"]["percent"])

  return exp;
  // temporary ;
}

void log_exp(int x, string type, object tmp) {
  if((x > 1000 || x < -1000) && userp(TO)) {
    log_file("exp", "<<<"+
            query_name()+" received "+x+" ("+type+")exp from "+ (string)previous_object()->query_name()+"\n");
    log_file("exp",
            "  (creator = "+previous_object()->query_creator()+")\n"+
            "  (uid: "+getuid(previous_object())+" "+file_name(previous_object())+")\n");
    if (objectp(tmp) && (tmp != previous_object()))
      log_file("exp",
               "  (creator = "+tmp->query_creator()+")\n"+
              "  (uid: "+getuid(tmp)+" "+file_name(tmp)+")\n");

    log_file("exp", ctime(time()) + ">>>\n");
  }
}

int exp_buffer(int exp)
{
    int level,max,total_exp,allowed;
    if(!objectp(TO)) { return exp; }
    if(!userp(TO)) { return exp; }
    if(avatarp(TO)) { return exp; }
    if(exp < 1) { return exp; }
    if(!intp(level = query_highest_level())) { return exp; }
    total_exp = (int)TO->query_exp();
    max = EXP_NEEDED[41];
    allowed = max - total_exp;
    if(allowed < 0) { allowed = 0; }
    if(exp > allowed) { return allowed; }
    return exp;
}

int resolve_auto_tax(int exp)
{
    int days,hours,time,limit,bonuslimit,level,mod,perc;
    string *classes=({});
    if(!objectp(TO)) { return exp; }
    if(!userp(TO)) { return exp; }
    if(avatarp(TO)) { return exp; }
    if(exp < 1) { return exp; }
    if((int)TO->query_property("ignore tax")) return exp; //installed to stop imm-granted exp going awry. Nienne, 04/10
    if(!intp(level=query_base_character_level())) { return exp; }
    if(!level) { return exp; }

    time    = (int)TO->query_age();
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
  if(!userp(TO))
    return;
  if(userp(TO) && (exp >0) && TO->query_party())
  {
    PARTY_OB->calculate_exp(TO->query_party(), exp, previous_object());
    return;
  }
  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  if (has_XP_rest())
    exp = use_XP_rest(exp);
  //going to change the way tax works - should remain 0 for everyone, unless
  //the have been granted a bonus - which should fall off after x amount of time - Saide
  //exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);

  log_exp(exp,"add",0);
  __internal_add_exp(exp);

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
      log_file("exp",">>> "+
               query_name()+" adjusted "+perc+"% exp from "+(string)tmp->query_name()+"\n");
      log_file("exp",
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
      log_file("exp","<<< "+
               query_name()+" adjusted "+((int)TO->query_exp() - oldexp)+" exp. \n");
  return returnval;
}
