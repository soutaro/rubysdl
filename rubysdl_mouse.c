/*
  Ruby/SDL   Ruby extension library for SDL

  Copyright (C) 2001 Ohbayashi Ippei
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
#include "rubysdl.h"

static void defineConstForMouse()
{
  rb_define_const(cEvent,"BUTTON_LEFT",INT2NUM(SDL_BUTTON_LEFT));
  rb_define_const(cEvent,"BUTTON_MIDDLE",INT2NUM(SDL_BUTTON_MIDDLE));
  rb_define_const(cEvent,"BUTTON_RIGHT",INT2NUM(SDL_BUTTON_RIGHT));
}

static VALUE sdl_getMouseState(VALUE mod)
{
  int x,y;
  Uint8 result;
  result=SDL_GetMouseState(&x,&y);
  return rb_ary_new3(5,INT2FIX(x),INT2FIX(y),BOOL(result&SDL_BUTTON_LMASK),
		     BOOL(result&SDL_BUTTON_MMASK),
		     BOOL(result&SDL_BUTTON_RMASK));
}
void init_mouse()
{
  mMouse=rb_define_module_under(mSDL,"Mouse");
  rb_define_module_function(mMouse,"state",sdl_getMouseState,0);

  defineConstForMouse();
}