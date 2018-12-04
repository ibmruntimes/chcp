/** **********************************************************************
 * Copyright 2018 IBM Corp.
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
 ************************************************************************/
'use strict';
var chcp = require('../index');
var tap = require('tap');

var cp = chcp.getConsoleCodePage();
var cp1 = 0;
var cp2 = 0;
if (cp === 437) {
  cp1 = 850;
  chcp.setConsoleCodePage(cp1);
  cp2 = chcp.getConsoleCodePage();
  tap.equal(cp1, cp2);
} else {
  cp1 = 437;
  chcp.setConsoleCodePage(cp1);
  cp2 = chcp.getConsoleCodePage();
  tap.equal(cp1, cp2);
}

chcp.setConsoleCodePage(cp);
