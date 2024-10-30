package com.microsoft.hackathon.demo.controller;

import com.microsoft.hackathon.demo.model.Author;
import io.cucumber.java.en.Given;
import io.cucumber.java.en.Then;
import io.cucumber.java.en.When;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;
import org.springframework.web.util.UriComponentsBuilder;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

public class AuthorControllerStepDefinitions {

    @Autowired
    private TestRestTemplate restTemplate;

    private ResponseEntity<Author> responseEntity;
    private Author author;

    @Given("the author details are provided")
    public void theAuthorDetailsAreProvided() {
        author = new Author();
        author.setName("John Doe");
        author.setBio("An accomplished author.");
    }

    @Given("the author details are incomplete")
    public void theAuthorDetailsAreIncomplete() {
        author = new Author();
        author.setName(""); // Missing name
    }

    @When("the client sends a POST request to \"/authors\"")
    public void theClientSendsAPostRequestToAuthors() {
        HttpHeaders headers = new HttpHeaders();
        HttpEntity<Author> request = new HttpEntity<>(author, headers);
        responseEntity = restTemplate.exchange("/authors", HttpMethod.POST, request, Author.class);
    }

    @Then("the response status should be {int}")
    public void theResponseStatusShouldBe(int statusCode) {
        assertEquals(statusCode, responseEntity.getStatusCodeValue());
    }

    @Then("the response should contain the author details")
    public void theResponseShouldContainTheAuthorDetails() {
        Author responseAuthor = responseEntity.getBody();
        assertNotNull(responseAuthor);
        assertEquals(author.getName(), responseAuthor.getName());
        assertEquals(author.getBio(), responseAuthor.getBio());
    }

    @Then("the response should contain an error message")
    public void theResponseShouldContainAnErrorMessage() {
        String errorMessage = responseEntity.getBody().toString();
        assertNotNull(errorMessage);
        // Additional assertions can be added to check the error message content
    }
}