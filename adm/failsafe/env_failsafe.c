//	/std/living/env.c
//	from the Nightmare mudlib
//	contains environment variables
//	originally from the TMI distribution mudlib

private mapping env_var;

mixed query_env (string env);

int setenv (string env, mixed value)
{
  if(!env_var)
    env_var = ([]);
  
  if(env_var[env])
    {
      env_var[env] = value;
      return 1;
    }
  
  env_var += ([ env : value]);
  return 1;
}

int set_env (string env, mixed value) {
  return setenv(env, value);
}

mixed getenv(string env)
{
  if(!env_var) 
    {
      env_var = ([]);
      return 0;
    }
  return env_var[env];
}

mixed query_env(string env) {
  return getenv(env);
}

int remove_env (string env)
{
  if(env_var && env_var[env])
    {
      map_delete(env_var, env);
      return 1;
    }
  return 0;
}

string * regexp_query_env (string pattern)
{
   string *vars, *env;

   vars = keys(env_var);
   vars -= ({ 0 }); /* may as well skip all the "deleted" ones for now */
   env = regexp (vars, pattern);
   if (!env) 
     env = ({});
   return env;
}
