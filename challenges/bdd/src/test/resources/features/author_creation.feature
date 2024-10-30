Feature: Author Creation

  Scenario: Successfully create a new author
    Given the author details are provided
    When the client sends a POST request to "/authors"
    Then the response status should be 201
    And the response should contain the author details

  Scenario: Fail to create an author with missing details
    Given the author details are incomplete
    When the client sends a POST request to "/authors"
    Then the response status should be 400
    And the response should contain an error message
