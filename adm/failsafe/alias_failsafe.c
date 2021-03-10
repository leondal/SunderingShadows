//	/std/user/alias.c
//	from the Nightmare mudlib
//	handles player aliasing
//	created by someone at TMI
//	modified for the Nightmare mudlib by Descartes of Borg 30 january 1993

mapping alias;
mapping xverb;

void add_alias(string verb, string cmd);

void init_aliases() {
    if(!alias) alias = ([]);
    if(!xverb) xverb = ([]);
}

void clear_aliases() {
    alias = ([]);
    xverb = ([]);
}

mapping query_aliases() { return alias+xverb; }

string query_alias(string str) {
    if(alias[str]) return alias[str];
    else return xverb[str];
}

void add_alias(string verb, string cmd) {
  if (verb[0] == '$')
	xverb[verb] = cmd;
  else {
    alias[verb] = cmd;
  }
}

void remove_alias(string verb) {
  if (alias[verb])
    map_delete(alias, verb);
  else if (xverb[verb])
    map_delete(xverb, verb);
}

string
replace_words(string orig, string *words) {
  string ret, tmp;
  string *parts;
  int i, num;

  parts = explode (orig+"$","$");
  if (!parts)
    return orig;
  ret = orig;
  for (i = 0; i < sizeof(parts); i++) {
      if (parts[i][0] == '*')
	ret = replace_string(orig,"$*",implode(words," "));
      else {
	  if (sscanf(parts[i],"%d%*s",num) == 0)
	    if (sscanf(parts[i],"%d",num) == 0)
	      continue;
	  if (num > 0 && num <= sizeof(words))
	    {
	      tmp = sprintf ("$%d",num);
	      ret = replace_string(ret,tmp,words[num-1]);
	    }
	}
    }
  return ret;
}


string do_xverb(string str) {
  string *xv, ret, tmp, *words;
  int i;

  if (!xverb)
    return 0;
  xv = keys(xverb);
  for (i = 0; i < sizeof(xv); i++) {
      xv[i] = xv[i][1..(strlen(xv[i])-1)];
      if (str[0 .. (strlen(xv[i]) - 1)] == xv[i]) {
	  str = str[strlen(xv[i]) .. (strlen(str) + 1)];
	  words = explode (str+" "," ");
	  if (!words)
	    words = ({str});
	  ret = replace_words(xverb["$"+xv[i]],words);
	  return ret;
	}
    }
  return 0;
}

string do_alias(string str) {
  string *words, tmp, ret;
  
  if (!str || str == "")
    return "";
  tmp = do_xverb(str);
  if (tmp)
    return tmp;
  if (!alias)
    return str;
  tmp = str;
  words = explode(str+" "," ");
  if (!words)
    words = ({tmp});
   if(sizeof(words) == 0) return "";
  if (alias[words[0]]) {
      ret = alias[words[0]];
      ret = replace_words(ret,words[1..(sizeof(words)+1)]);
      return ret;
    }
  return implode (words," ");
}
