project(FilterGradientMagnitude)

file(GLOB src
  "*.cpp"
)

add_executable(${PROJECT_NAME} ${src} )

target_link_libraries(
  ${PROJECT_NAME} 
  ${ITK_LIBRARIES} 
  ${VTK_LIBRARIES}
)