# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       | If User is a new Voter - Checking the VoterId | Data | Success - Program continues  | Success - Program continues | Scenario based |
|  H_02       | If User is a spam Voter - Checking the VoterId | Data | Fails - Program exit  | Fails - Program exit | Scenario based |

## Table no: Low level test plan

| **Test ID** | **H ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|----------|----------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       | H_01     | Vote for a particular candidate | Data | Vote Polled | Vote Polled | Requirement based |
|  L_02       | H_01     | User shall add new candidates | Data | Candidate added | Candidate added | Requirement based |
|  L_03       | H-01     | View the list of Voters |  Data | List of Voters | List Of Voters | Requirement based |
|  L_04       | H_01     | View the list of Candidates |  Data | List of Candidates | List Of candidates | Requirement based |
|  L_05       | H_01     | View the votes received by each Candidate | Data | Live Count | Live Count | Requirement based |
|  L_06       | H_01     | User wants to exit | Data | Exit | Exit | Requirement based |

