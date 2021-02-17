#include <napi.h>
#include <iostream>

Napi::String Dectobin(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
  }

  std::string arg0 = info[0].As<Napi::String>().Utf8Value();
  long long number = std::stoll (arg0);
  long long mod;
  std::string binary;
  std::string byte;

  while(number >= 1) {
    mod = number % 2;
    number = number / 2;
    byte = (mod == 0) ? "0" : "1";
    binary = byte + binary;
  }

  return Napi::String::New(env, binary);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "dec2bin"), Napi::Function::New(env, Dectobin));
  return exports;
}

NODE_API_MODULE(addon, Init);