/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_CONTRIB_IGNITE_KERNELS_CLIENT_IGNITE_PLAIN_CLIENT_H_
#define TENSORFLOW_CONTRIB_IGNITE_KERNELS_CLIENT_IGNITE_PLAIN_CLIENT_H_

#include "tensorflow_io/ignite/kernels/client/ignite_client.h"

namespace tensorflow {

class PlainClient : public Client {
 public:
  PlainClient(string host, int port, bool big_endian);
  ~PlainClient();

  Status Connect() override;
  Status Disconnect() override;
  bool IsConnected() override;
  int GetSocketDescriptor() override;
  Status ReadData(uint8_t* buf, const int32_t length) override;
  Status WriteData(const uint8_t* buf, const int32_t length) override;

 private:
  const string host_;
  const int port_;
  int sock_;
};

}  // namespace tensorflow

#endif  // TENSORFLOW_CONTRIB_IGNITE_KERNELS_CLIENT_IGNITE_PLAIN_CLIENT_H_
