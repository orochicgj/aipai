# Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
#
# Use of this source code is governed by a BSD-style license
# that can be found in the LICENSE file in the root of the source
# tree. An additional intellectual property rights grant can be found
# in the file PATENTS.  All contributing project authors may
# be found in the AUTHORS file in the root of the source tree.

{
'includes': ['../webrtc/build/common.gypi',],
  'targets': [
    {
      'target_name': 'protobuf_proto',
      'type': 'static_library',
      'sources': [ '../third_party/protobuf/src/google/protobuf/unittest_lite.proto', ],
      'variables': {
        'proto_in_dir': ['../third_party/protobuf/src/', '../third_party/protobuf/src/google/protobuf/'],
        # Workaround to protect against gyp's pathname relativization when this
        # file is included by modules.gyp.
        'proto_out_protected': 'webrtc/audio_processing',
        'proto_out_dir': '<(proto_out_protected)',
      },
      'includes': [ '../build/protoc.gypi', ],
    },
  ],
}
