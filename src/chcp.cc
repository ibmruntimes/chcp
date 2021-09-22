/*******************************************************************************
 * Copyright 2018, IBM Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/

#include <napi.h>
#include <windows.h>

using Napi::Value;
using Napi::CallbackInfo;
using Napi::Env;
using Napi::Number;
using Napi::TypeError;
using Napi::Object;
using Napi::String;
using Napi::Function;


Value GetConsoleCodePage(const CallbackInfo& info) {
  Env env = info.Env();
  Number chcp = Number::New(env, GetConsoleOutputCP());
  return chcp;
}

Value SetConsoleCodePage(const CallbackInfo& info) {
  Env env = info.Env();
  if (info.Length() < 1 || !info[0].IsNumber()) {
    TypeError::New(env, "argument should be a number.")
      .ThrowAsJavaScriptException();
    return env.Null();
  }
  UINT chcp = info[0].As<Number>().Int32Value();
  BOOL ret = SetConsoleOutputCP(chcp);

  return ret
    ? Number::New(env, GetLastError())
    : Number::New(env, 0);
}

Object Init(Env env, Object exports) {
  exports.Set(String::New(env, "getConsoleCodePage"), Function::New(env, GetConsoleCodePage));
  exports.Set(String::New(env, "setConsoleCodePage"), Function::New(env, SetConsoleCodePage));
  return exports;
}

NODE_API_MODULE(addon, Init)
