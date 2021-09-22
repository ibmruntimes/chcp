{
  "targets": [
  {
    "target_name": "chcp",
    "sources": [ "src/chcp.cc" ],
    "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")"],
    "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"]
  }]
}
