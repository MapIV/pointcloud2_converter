SCRIPT_DIR=$(cd $(dirname $0); pwd)

INCLUDE_FILES=$(find $SCRIPT_DIR -name "*.hpp")
SOURCE_FILES=$(find $SCRIPT_DIR -name "*.cpp")
PACKAGE_FILE=$(find $SCRIPT_DIR -name "*.xml")
CMAKELISTS_FILE=$(find $SCRIPT_DIR -name "CMakeLists.txt")

sed -i "s/TEMPLATE/$1/g" $INCLUDE_FILES $SOURCE_FILES $PACKAGE_FILE $CMAKELISTS_FILE
sed -i "s/Template/$2/g" $INCLUDE_FILES $SOURCE_FILES $PACKAGE_FILE $CMAKELISTS_FILE
sed -i "s/template/$3/g" $INCLUDE_FILES $SOURCE_FILES $PACKAGE_FILE $CMAKELISTS_FILE

rename s/template/$3/g $INCLUDE_FILES $SOURCE_FILES
rename s/template/$3/g $(find $SCRIPT_DIR)
