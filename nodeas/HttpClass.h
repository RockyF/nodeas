/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef __avmplus_HttpClass__
#define __avmplus_HttpClass__

namespace avmplus
{
 struct Http;
 
 class HttpScript
 {
 private:
  static bool trusted(ScriptObject* self) { return self->toplevel()->sampler_trusted(self); }
  explicit HttpScript(); // unimplemented, not constructable
  
 public:
  enum { GET = 1, SET = 2 };
 };

 class HttpClass : public ClassClosure
 {
 public:
  HttpClass(VTable *vtable);
  ScriptObject *createInstance(VTable *ivtable, ScriptObject *delegate);

  uint32 startlisten(uint32 port);
  uint32 accept(uint32 socket);
  uint32 send(uint32 connfd, Stringp data);
  Stringp recv(uint32 connfd);
  void close(uint32 connfd);

  DECLARE_SLOTS_HttpClass;
 };

 class HttpObject : public ScriptObject
 {
  friend class HttpScript;
 public:
  HttpObject(VTable *vtable, ScriptObject *delegate);

  DECLARE_SLOTS_HttpObject;
 };
}
#endif // __avmplus_HttpScript__
