//	/std/user/olias.c
//	from the Nightmare mudlib
//	handles player oliasing
//	created by someone at TMI
//	modified for the Nightmare mudlib by Descartes of Borg 30 january 1993

mapping olias;
mapping xverb;

void add_olias(string verb, string cmd);

void init_oliases() {
    if(!olias) olias = ([]);
    if(!xverb) xverb = ([]);
}

void clear_oliases() {
    olias = ([]);
    xverb = ([]);
}

mapping query_oliases() { return olias+xverb; }

string query_olias(string str) {
    if(olias[str]) return olias[str];
    else return xverb[str];
}

void add_olias(string verb, string cmd) {
  if (verb[0] == '$')
	xverb[verb] = cmd;
  else {
    olias[verb] = cmd;
  }
}

void remove_olias(string verb) {
  if (olias[verb])
    map_delete(olias, verb);
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

string do_olias(string str) {
  string *words, tmp, ret;
  
  if (!str || str == "")
    return "";
  tmp = do_xverb(str);
  if (tmp)
    return tmp;
  if (!olias)
    return str;
  tmp = str;
  words = explode(str+" "," ");
  if (!words)
    words = ({tmp});
  if (olias[words[0]]) {
      ret = olias[words[0]];
      ret = replace_words(ret,words[1..(sizeof(words)+1)]);
      return ret;
    }
  return implode (words," ");
}
