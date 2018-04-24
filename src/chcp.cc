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

#include <node.h>
#include <windows.h>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::String;
using v8::Value;
using v8::Exception;
using v8::Object;
using v8::Int32;


void GetConsoleCodePage(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Number> chcp = Number::New(isolate, GetConsoleOutputCP());
  args.GetReturnValue().Set(chcp);
}

void SetConsoleCodePage(const FunctionCallbackInfo<Value>& args) {
  DWORD error = 0, chcp = 0, ret = 0;
  Isolate* isolate = args.GetIsolate();
  if (!args[0]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "argument should be a number.")));
    return;
  }
  chcp = static_cast<int>(args[0]->Int32Value());
  ret = SetConsoleOutputCP(chcp);
  if (!ret)
    error = GetLastError();
 args.GetReturnValue().Set(Int32::New(isolate, error));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "getConsoleCodePage", GetConsoleCodePage);
  NODE_SET_METHOD(exports, "setConsoleCodePage", SetConsoleCodePage);
}
NODE_MODULE(NODE_GYP_MODULE_NAME, init)

