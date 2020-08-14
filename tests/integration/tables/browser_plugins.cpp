/**
 * Copyright (c) 2014-present, The osquery authors
 *
 * This source code is licensed as defined by the LICENSE file found in the
 * root directory of this source tree.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR GPL-2.0-only)
 */

// Sanity check integration test for browser_plugins
// Spec file: specs/darwin/browser_plugins.table

#include <osquery/tests/integration/tables/helper.h>

namespace osquery {
namespace table_tests {

class browserPlugins : public testing::Test {
 protected:
  void SetUp() override {
    setUpEnvironment();
  }
};

TEST_F(browserPlugins, test_sanity) {
  ValidationMap row_map = {
      {"uid", IntType},
      {"name", NormalType},
      {"identifier", NormalType},
      {"version", NormalType},
      {"sdk", NormalType},
      {"description", NormalType},
      {"development_region", NormalType},
      {"native", IntType},
      {"path", NormalType},
      {"disabled", IntType},
  };

  auto const data = execute_query("select * from browser_plugins");
  ASSERT_FALSE(data.empty());
  validate_rows(data, row_map);

  auto const datauser =
      execute_query("select * from browser_plugins where uid = 0");
  ASSERT_FALSE(datauser.empty());
  validate_rows(datauser, row_map);
}

} // namespace table_tests
} // namespace osquery
