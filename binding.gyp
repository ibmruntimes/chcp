{
  # NOTE: 'module_name' and 'module_path' come from the 'binary' property in package.json
  # node-pre-gyp handles passing them down to node-gyp when you build from source
  "targets": [
    {
      "target_name": "<(module_name)",
      "sources": [ "src/chcp.cc" ],
      "product_dir": "<(module_path)",
    }
  ]
}
