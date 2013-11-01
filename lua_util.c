/*
* Copyright (C) 2013 Lourival Vieira Neto <lourival.neto@gmail.com>.
* All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include "lua_util.h"

void lua_getnfield(lua_State *L, int index, lua_Number number)
{
  lua_pushnumber(L, number);
  if (index < 0)
    index--;
  lua_gettable(L, index);
}

void * lua_malloc(lua_State *L, size_t size)
{
  void * ud = NULL;
  lua_Alloc alloc = lua_getallocf(L, &ud);
  return alloc(ud, NULL, 0, size);
}

void lua_free(lua_State *L, void * ptr, size_t size)
{
  void * ud = NULL;
  lua_Alloc alloc = lua_getallocf(L, &ud);
  alloc(ud, ptr, size, 0);
}

